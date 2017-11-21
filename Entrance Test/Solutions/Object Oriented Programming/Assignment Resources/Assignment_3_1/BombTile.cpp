// BombTile.cpp
#include <iostream>

#include "BombTile.h"
#include "DamageInteraction.h"

const BombTile::DamageRange BombTile::s_damageRange(3, 6);

BombTile::BombTile()
{
	m_type = k_bomb;
	m_state = TileState::k_active;
	m_interaction = new DamageInteraction(s_damageRange);
}

BombTile::~BombTile()
{
	delete m_interaction;
	m_interaction = nullptr;
}

Tile::TileType BombTile::GetType() const
{
	return m_type;
}

void BombTile::Render()
{
    if (m_state == TileState::k_active)
        std::cout << "*";
    else
        std::cout << "#";
}

void BombTile::OnEnter(Entity* pEntity)
{
	switch (m_state)
	{
		case TileState::k_active:
			m_interaction->ExecuteOn(pEntity);
			m_state = TileState::k_dead;
	    break;

		case TileState::k_dead:
			break;

		default:
			break;
	}
}



