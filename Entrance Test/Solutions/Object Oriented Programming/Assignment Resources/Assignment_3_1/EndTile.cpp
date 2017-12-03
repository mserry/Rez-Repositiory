// EndTile.cpp
#include "EndTile.h"
#include "World.h"
#include <iostream>

extern World* g_pWorld;  // let's us access a global variable declared in another CPP

EndTile::EndTile()
{
	m_type = k_end;
	m_state = TileState::k_ready;
	m_interaction = nullptr;
}

EndTile::EndTile(int xPos, int yPos)
{
	m_xPos = xPos;
	m_yPos = yPos;
}

EndTile::~EndTile() {}

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
	return m_type;
}
