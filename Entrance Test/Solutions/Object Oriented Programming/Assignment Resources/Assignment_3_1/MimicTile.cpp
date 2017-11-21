// MimicTile.cpp
#include <iostream>

#include "MimicTile.h"


using std::cout;

MimicTile::MimicTile()
{
	m_state = TileState::k_hidden;
	m_type = k_mimic;
}

MimicTile::~MimicTile() {}

void MimicTile::Render()
{
    switch (m_state)
    {
        case TileState::k_hidden:
            cout << "$";
            break;

		case TileState::k_revealed:
        case TileState::k_active:
            cout << "*";
            break;

        case TileState::k_dead:
            cout << "#";
            break;
    }
}

void MimicTile::OnEnter(Entity* pEntity)
{
	if (m_state == TileState::k_hidden)
		m_state = TileState::k_active;

	BombTile::OnEnter(pEntity);
}

Tile::TileType MimicTile::GetType() const
{
	return m_type;
}