#include "Renderer.h"
#include "World.h"
#include "Player.h"
#include "Tile.h"
#include <ostream>
#include <iostream>

extern World* g_pWorld;


void Renderer::Render() const
{
	//RenderUi();

	RenderObjects();

	//RenderEntities();
}

void Renderer::RenderUi() const
{
	const auto player = g_pWorld->GetPlayer();

	player->RenderPlayerUi();
}

void Renderer::RenderEntities() const
{
	const auto entities = g_pWorld->GetEntities();

	for (size_t i = 0; i < entities.size(); ++i)
	{
		if(entities[i])
		{
			entities[i]->Render();
		}
	}
}

void Renderer::RenderObjects() const
{
	const auto tiles = g_pWorld->GetTiles();
	const auto worldWidth = g_pWorld->GetWorldWidth();
	const auto worldHeight = g_pWorld->GetWorldHeight();

	for(int j = 0; j < worldHeight; ++j)
	{
		for (int i = 0; i < worldWidth; ++i)
		{
			int index = (j * worldHeight) + i;
		
			if(tiles[index])
			{
				tiles[index]->Render();
			}
		}

		std::cout << std::endl;
	}
}

Renderer::Renderer() {}
Renderer::~Renderer() {}