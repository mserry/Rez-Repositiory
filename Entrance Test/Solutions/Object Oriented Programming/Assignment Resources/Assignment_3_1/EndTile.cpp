// EndTile.cpp
#include "EndTile.h"
#include "World.h"
#include <iostream>

extern World* g_pWorld;  // let's us access a global variable declared in another CPP

EndTile::EndTile() : Tile()
{
	m_type = k_end;
	m_state = TileState::k_ready;
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
