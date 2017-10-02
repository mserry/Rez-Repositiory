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

void TreasureTile::Draw()
{
    if (!m_collected)
        std::cout << "$";
    else
        std::cout << ".";
}

void TreasureTile::OnEnter(Player* pPlayer)
{
	m_interaction->ExecuteOn(pPlayer);
}

