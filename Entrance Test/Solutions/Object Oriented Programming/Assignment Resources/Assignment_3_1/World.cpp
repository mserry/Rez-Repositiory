// World.cpp

#include "World.h"
#include "Tile.h"
#include "Player.h"
#include "InputHandler.h"

#include "FloorTile.h"
#include "TreasureTile.h"
#include "BombTile.h"
#include "MimicTile.h"
#include "EndTile.h"

#include <iostream>
#include <assert.h>
#include "Chaser.h"
#include "Evader.h"

using std::cout;
using std::endl;

const World::TileProbability World::s_tileProbabilities[static_cast<int>(TileType::k_numTiles)] =
{
    World::TileProbability(800, TileType::k_floor),
    World::TileProbability(75, TileType::k_bomb),
    World::TileProbability(75, TileType::k_treasure),
    World::TileProbability(50, TileType::k_mimic),
};

const int World::s_chaserEntityProbability = 30;
const int World::s_evaderEntityProbability = 70;

//TODO: Messy Class EU (TOO MANY RESPONSIBLITIES..)
World::World()
	: m_width(0)
	  , m_height(0)
	  , m_entityCount(0), m_ppGrid(nullptr)
	  , m_pPlayer(nullptr)
	  , m_gameOver(false), m_playerTileIndex(0)
{
	//
}

World::~World()
{
    for (int i = 0; i < m_width * m_height; ++i)
    {
        delete m_ppGrid[i];
    }
    delete[] m_ppGrid;
    m_ppGrid = nullptr;

    delete m_pPlayer;
    m_pPlayer = nullptr;

	//de-allocating entities.
	for(size_t j = 0 ;j < m_entities.size(); ++j)
	{
		delete m_entities[j];
	}
	m_entities.clear();
}


void World::Init(int width, int height, int entitiesCount)
{
    // if we have a grid, destroy it
    if (m_ppGrid)
    {
        for (int i = 0; i < m_width * m_height; ++i)
        {
            delete m_ppGrid[i];
        }
        delete[] m_ppGrid;
        m_ppGrid = nullptr;
    }

    // create and fill the grid with nothing
    m_ppGrid = new Tile* [width * height];
    for (int i = 0; i < width * height; ++i)
    {
        m_ppGrid[i] = nullptr;
    }

    // set the width & height
    m_width = width;
    m_height = height;
	m_entityCount = entitiesCount;

}

void World::CreatePlayer(int x, int y)
{
    assert(x >= 0 && x < m_width);
    assert(y >= 0 && y < m_height);

    m_pPlayer = new Player(x, y);
	m_entities.push_back(m_pPlayer);
}

Entity* World::CreateEntity(int x, int y, const EntityType type) const
{
	assert(x >= 0 && x < m_width);
	assert(y >= 0 && y < m_height);

	switch(type)
	{
		case EntityType::k_chaser:
			return new Chaser(x,y);

		case EntityType::k_evader:
			return new Evader(x,y);

		default: ;
	}

	return nullptr;
}

void World::GenerateWorld()
{
    // calculate the max probability
    int maxProbability = 0;
    for (int i = 0; i < (int)TileType::k_numTiles; ++i)
    {
        maxProbability += s_tileProbabilities[i].first;
    }

    // create the start and end tiles
    int lastIndex = (m_width * m_height) - 1;
	m_ppGrid[lastIndex] = new EndTile(m_height * m_width, m_height * m_width);  // special tile for ending the level; there is only one of these
    m_ppGrid[0] = new FloorTile(0,0);  // guarantee that the starting location is open

    // guarantee at least one mimic
    int randomTile = (rand() % (lastIndex - 1)) + 1;
    assert(m_ppGrid[randomTile] == nullptr);  // if this fires, it means our math is wrong
    m_ppGrid[randomTile] = new MimicTile();

    // populate the rest of the world
    for (int tileIndex = 1; tileIndex < (m_width * m_height) - 1; ++tileIndex)
    {
        // skip this tile if we've already set it
        if (m_ppGrid[tileIndex] != nullptr)
            continue;

        int roll = rand() % maxProbability;
        int probabilityIndex = 0;
        while (true)
        {
            roll -= s_tileProbabilities[probabilityIndex].first;
            if (roll < 0)
                break;
            ++probabilityIndex;
        }

        assert(probabilityIndex >= 0 && probabilityIndex < (int)TileType::k_numTiles);

        switch (s_tileProbabilities[probabilityIndex].second)
        {
            case TileType::k_floor:
                m_ppGrid[tileIndex] = new FloorTile;
                break;

            case TileType::k_bomb:
                m_ppGrid[tileIndex] = new BombTile;
                break;

            case TileType::k_treasure:
                m_ppGrid[tileIndex] = new TreasureTile;
                break;

            case TileType::k_mimic:
                m_ppGrid[tileIndex] = new MimicTile;
                break;

            default:
                cout << "ERROR: Invalid type type.\n";
                break;
        }
    }


	//set tile world positions
	for(int y = 0; y < m_height; ++y)
	{
		for(int x = 0; x < m_width; ++x)
		{
			int tileIndex = (y * m_width) + x;

			m_ppGrid[tileIndex]->SetX(x);
			m_ppGrid[tileIndex]->SetY(y);
		}
	}
}

void World::Draw()
{
    system("cls");
	
	m_pPlayer->RenderPlayerUi();

    for (int y = 0; y < m_height; ++y)
    {
        for (int x = 0; x < m_width; ++x)
        {
			Entity* pEntity = GetEntityOnTile(x, y);

            if (pEntity != nullptr)
            {
               pEntity->Render();
            }
            else
            {
                int index = (y * m_height) + x;
                m_ppGrid[index]->Render();
            }
        }
        cout << endl;
    }
}

void World::Update()
{
    if (!m_pPlayer->Update())
    {
        m_pPlayer->Kill();  // ending the game prematurely does not result in a win
        EndGame();
        return;
    }


	InputHandler::ProcessInput();

    int x = m_pPlayer->GetX();
    int y = m_pPlayer->GetY();

    // this is a death arena, so check to see if we went over the edge of the world
    if (x < 0 || y < 0 || x >= m_width || y >= m_height)
    {
        m_pPlayer->Kill();
        EndGame();
        return;
    }

    // process the tile the player is on
    m_playerTileIndex = (y * m_width) + x;
    m_ppGrid[m_playerTileIndex]->OnEnter(m_pPlayer);


	//process entities.
	for (Entity* pEntity : m_entities)
	{
		const int xPos = pEntity->GetX();
		const int yPos = pEntity->GetY();

		if (!pEntity->Update() || (xPos < 0 || yPos < 0 || xPos >= m_width || yPos >= m_height))
		{
			pEntity->Kill();
		}

		int tileIndex = (yPos * m_width) + xPos;
		m_ppGrid[tileIndex]->OnEnter(pEntity);
	}
}

std::vector<Entity*> World::GetEntities() const
{
	return m_entities;
}

int World::GetWorldWidth() const
{
	return m_width;
}

int World::GetWorldHeight() const
{
	return m_height;
}

void World::EndGame()
{
    if (!m_pPlayer->IsDead())
    {
        cout << "\n\nYou won!\n\n";
        cout << "Your final score is: " << m_pPlayer->CalculateScore() << "\n";
    }
    else
    {
        cout << "\n\nYou have died.\n\n";
    }

    m_gameOver = true;
}

Player* World::GetPlayer() const
{
	return (!m_pPlayer) ? nullptr : m_pPlayer;
}

Tile** World::GetTiles() const
{
	return (!m_ppGrid) ? nullptr : m_ppGrid;
}

int World::GetPlayerTileIndex() const
{
	return m_playerTileIndex;
}

int World::GetPlayerXPos() const
{
	return m_pPlayer->GetX();
}

int World::GetPlayerYPos() const
{
	return m_pPlayer->GetY();
}

std::vector<Tile*> World::GetNeighbourTiles(int x, int y) const
{
	//ensure central tile is properly placed.
	assert(x >= 0 && x < m_width);
	assert(y >= 0 && y < m_height);

	std::vector<Tile*> neighbourTiles;

	for(int gridRow = y - 1; gridRow <= y + 1 && gridRow < m_height; ++gridRow)
	{
		for(int gridCol = x - 1; gridCol <= x + 1 && gridCol < m_width; ++gridCol)
		{
			//skip center tile.
			if (gridCol == x && gridRow == y) continue;

			int tilePos = (gridRow * m_width) + gridCol;
			Tile* pGridTile = m_ppGrid[tilePos];

			if(pGridTile != nullptr)
			{
				neighbourTiles.push_back(pGridTile);
			}
		}
	}

	return neighbourTiles;
}

std::vector<Tile*> World::GetAdjacentTiles(int x, int y) const
{
	//ensure central tile is properly placed.
	assert(x >= 0 && x < m_width);
	assert(y >= 0 && y < m_height);

	std::vector<Tile*> adjTiles;

	int topTileIndex = ((y - 1) * m_height) + x;
	adjTiles.push_back(m_ppGrid[topTileIndex]);

	int botTileIndex = ((y + 1) * m_height) + x;
	adjTiles.push_back(m_ppGrid[botTileIndex]);

	int leftTileIndex = (y * m_height) + (x - 1);
	adjTiles.push_back(m_ppGrid[leftTileIndex]);

	int rightTileIndex = (y * m_height) + (x + 1);
	adjTiles.push_back(m_ppGrid[rightTileIndex]);

	return adjTiles;
}

Entity* World::GetEntityOnTile(int xPos, int yPos) const
{
	for(size_t i = 0; i < m_entities.size(); ++i)
	{
		const bool IsOnTile = m_entities[i]->GetX() == xPos && m_entities[i]->GetY() == yPos;

		if(IsOnTile)
		{
			return m_entities[i];
		}
	}
	return nullptr;
}


void World::DetectAdjacentMimics() const
{
	if (m_pPlayer->GetMimicMoves() <= 0) return;

	int x = m_pPlayer->GetX();
	int y = m_pPlayer->GetY();

	std::vector<Tile*> neighbourTiles = GetNeighbourTiles(x, y);

	//find better way.
	if(neighbourTiles.size() < 7)
	{
		cout << "Not Enough Adjacent Tiles !";
		return;
	}

	for (Tile* pNeighbourTile : neighbourTiles)
	{
		assert(pNeighbourTile);

		if (pNeighbourTile != nullptr)
		{
			if (pNeighbourTile->GetType() == Tile::TileType::k_mimic)
			{
				pNeighbourTile->SetState(Tile::TileState::k_active);
			}
		}
	}


	m_pPlayer->DecrMimicMoves();
	m_pPlayer->IncrementMoveCount();
}


void World::GenerateEntities()
{
	//Generating Entities.
	for (int i = 0; i < m_entityCount; ++i)
	{
		int roll = rand() % 100;
		EntityType spawnedEntityType = roll > s_evaderEntityProbability ? EntityType::k_evader : EntityType::k_chaser;

		int rndXPos = rand() % m_width;
		int rndYPos = rand() % m_height;

		Entity* newEntity = CreateEntity(rndXPos, rndYPos, spawnedEntityType);
		if (newEntity)
		{
			m_entities.push_back(newEntity);
			cout << "Added Entities !";
		}
	}
}
