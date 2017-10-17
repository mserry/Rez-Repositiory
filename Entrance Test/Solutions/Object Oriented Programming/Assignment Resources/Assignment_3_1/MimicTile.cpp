// MimicTile.cpp
#include "MimicTile.h"
#include <iostream>

using std::cout;

MimicTile::MimicTile()
{
	m_state = State::k_hidden;
	m_dirty = true;
}

void MimicTile::Render()
{
	if (!IsDirty()) return;

    switch (m_state)
    {
        case State::k_hidden:
            cout << "$";
            break;

        case State::k_active:
            cout << "*";
            break;

        case State::k_dead:
            cout << "#";
            break;

        default:
            cout << "ERROR: Invalid state in MimiTile";
            break;
    }
}

void MimicTile::OnEnter(Player* pPlayer)
{
	if(m_state != State::k_hidden) return;

	m_state = State::k_active;
	BombTile::OnEnter(pPlayer);
}

Tile::TileType MimicTile::GetType() const
{
	return TileType::k_mimic;
}

bool MimicTile::IsDirty() const
{
	return m_state != State::k_hidden; 
}

