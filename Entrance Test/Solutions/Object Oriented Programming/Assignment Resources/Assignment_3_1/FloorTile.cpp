// FloorTile.cpp
#include "FloorTile.h"
#include <iostream>

using std::cout;

FloorTile::FloorTile() : Tile()
{
	m_state = TileState::k_ready;
	m_type = k_floor;
}

FloorTile::~FloorTile() {}

void FloorTile::Render()
{
    cout << ".";
}

Tile::TileType FloorTile::GetType() const
{
	return m_type;
}
