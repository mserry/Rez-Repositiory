// TreasureTile.cpp
#include "TreasureTile.h"
#include "Player.h"
#include <iostream>
#include "TreasureInteraction.h"

const TreasureTile::TreasureRange TreasureTile::s_treasureRange(50, 150);

TreasureTile::TreasureTile()
    : m_collected(false)
{
	m_interaction = new TreasureInteraction(this, s_treasureRange);
}

void TreasureTile::Render()
{
	switch (m_state)
	{
		case State::k_collected:
			std::cout << ".";
			break;

		case State::k_active:
			std::cout << "$";
			break;

		default:
			break;
	}
}

void TreasureTile::OnEnter(Player* pPlayer)
{
	if (m_state == State::k_collected) return;

	m_interaction->ExecuteOn(pPlayer);
	m_state = State::k_collected;
}

Tile::TileType TreasureTile::GetType() const
{
	return TileType::k_treasure;
}

