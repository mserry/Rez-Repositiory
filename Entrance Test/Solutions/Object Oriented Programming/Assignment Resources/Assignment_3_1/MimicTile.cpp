// MimicTile.cpp
#include <iostream>

#include "MimicTile.h"


using std::cout;

MimicTile::MimicTile()
{
	m_state = State::k_hidden;
	m_type = k_mimic;
}

MimicTile::~MimicTile() {}

void MimicTile::Render()
{
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

void MimicTile::OnEnter(Entity* pEntity)
{
	if(m_state != State::k_hidden) return;

	m_state = State::k_active;
	BombTile::OnEnter(pEntity);
}

Tile::TileType MimicTile::GetType() const
{
	return m_type;
}