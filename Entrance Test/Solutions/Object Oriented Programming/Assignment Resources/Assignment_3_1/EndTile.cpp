// EndTile.cpp
#include "EndTile.h"
#include "World.h"
#include <iostream>

extern World* g_pWorld;  // let's us access a global variable declared in another CPP

void EndTile::Render()
{
    std::cout << "H";
}

void EndTile::OnEnter(Entity* pEntity)
{
    g_pWorld->EndGame();
}

Tile::TileType EndTile::GetType() const
{
	return TileType::k_end;
}
