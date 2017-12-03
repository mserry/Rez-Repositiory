// FloorTile.cpp
#include "FloorTile.h"
#include <iostream>

using std::cout;

FloorTile::FloorTile()
{
	m_state = TileState::k_ready;
	m_type = k_floor;
	m_interaction = nullptr;
}

FloorTile::FloorTile(int xPos, int yPos)
{
	m_xPos = xPos;
	m_yPos = yPos;
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
