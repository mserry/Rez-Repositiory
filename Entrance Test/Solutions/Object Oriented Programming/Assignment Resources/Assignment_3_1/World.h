// World.h
#ifndef __WORLD_H__
#define __WORLD_H__

#include <utility>
#include <vector>

class Tile;
class Player;
class Entity;

enum class TileType
{
	k_floor,
	k_bomb,
	k_treasure,
	k_mimic,
	k_numTiles,
};

enum class EntityType
{
	k_evader,
	k_chaser,
	k_default,
};

class World
{
    typedef std::pair<int, TileType> TileProbability;

    static const TileProbability s_tileProbabilities[static_cast<int>(TileType::k_numTiles)];

	static const int s_evaderEntityProbability;
	static const int s_chaserEntityProbability;
    
	int m_width, m_height, m_entityCount;
    Tile** m_ppGrid;
    Player* m_pPlayer;
	std::vector<Entity*> m_entities;
    bool m_gameOver;

public:
	World();
	~World();

    // initialization
    void Init(int width, int height, int entitiesCount);
    void CreatePlayer(int x = 0, int y = 0);
    void GenerateWorld();
	void GenerateEntities();

    void Draw();
    void Update();

	//getters
	std::vector<Entity*> GetEntities() const;
	int GetWorldWidth() const;
	int GetWorldHeight() const;
	Player* GetPlayer() const;
	Tile** GetTiles() const;
	int GetPlayerTileIndex() const;
	int GetPlayerXPos() const;
	int GetPlayerYPos() const;
	
	//methods
	void DetectAdjacentMimics() const;
	std::vector<Tile*> GetAdjacentTiles(int x, int y) const;

	// end
    void EndGame();
    bool IsGameOver() const { return m_gameOver; }

	
private:
	Entity* CreateEntity(int x, int y, EntityType type)   const;
	std::vector<Tile*>  GetNeighbourTiles(int x, int y)   const;
	Entity*         GetEntityOnTile(int xPos, int yPos)   const;

private:
	int m_playerTileIndex;
};

#endif
