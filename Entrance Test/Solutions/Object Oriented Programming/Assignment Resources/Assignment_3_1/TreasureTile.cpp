// TreasureTile.cpp
#include <iostream>

#include "TreasureTile.h"
#include "TreasureInteraction.h"

const TreasureTile::TreasureRange TreasureTile::s_treasureRange(50, 150);

TreasureTile::TreasureTile() : Tile()
{
	m_state = TileState::k_active;
	m_type = k_treasure;

	m_treasureInteraction = new TreasureInteraction(s_treasureRange);
}

TreasureTile::~TreasureTile()
{
	if(m_treasureInteraction)
	{
		delete m_treasureInteraction;
		m_treasureInteraction = nullptr;
	}
}

void TreasureTile::Render()
{
	switch (m_state)
	{
		case TileState::k_collected:
			std::cout << ".";
			break;

		case TileState::k_active:
			std::cout << "$";
			break;

		default:
			break;
	}
}

void TreasureTile::OnEnter(Entity* pEntity)
{
	if (m_state == TileState::k_collected) return;

	m_treasureInteraction->ExecuteOn(pEntity);
	m_state = TileState::k_collected;
}

Tile::TileType TreasureTile::GetType() const
{
	return m_type;
}

