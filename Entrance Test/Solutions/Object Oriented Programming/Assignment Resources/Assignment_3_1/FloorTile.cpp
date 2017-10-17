// FloorTile.cpp
#include "FloorTile.h"
#include <iostream>

using std::cout;

void FloorTile::Render()
{
    cout << ".";
}

Tile::TileType FloorTile::GetType() const
{
	return TileType::k_floor;
}
