// BombTile.cpp
#include <iostream>

#include "BombTile.h"
#include "DamageInteraction.h"

const BombTile::DamageRange BombTile::s_damageRange(3, 6);

BombTile::BombTile() : Tile()
{
	m_type = k_bomb;
	m_state = TileState::k_active;

	m_dmgInteraction = new DamageInteraction(s_damageRange);
}

BombTile::~BombTile()
{
	if(m_dmgInteraction)
	{
		delete m_dmgInteraction;
		m_dmgInteraction = nullptr;
	}
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
	if(m_state == TileState::k_active)
	{
		m_dmgInteraction->ExecuteOn(pEntity);
		m_state = TileState::k_dead;
	}
}



