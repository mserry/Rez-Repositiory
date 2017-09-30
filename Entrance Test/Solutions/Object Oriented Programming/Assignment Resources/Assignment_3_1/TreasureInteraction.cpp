#include "TreasureInteraction.h"
#include "Player.h"
#include "DamageInteraction.h"

TreasureInteraction::TreasureInteraction(Tile* powner, std::pair<int, int> treasureRange) :
DamageInteraction(powner,treasureRange), m_collectedTreasure(false) {}


void TreasureInteraction::ExecuteOn(Player& player)
{
	if (m_collectedTreasure) return;

	player.AddGold(GetRndValInRange(m_range));
	m_collectedTreasure = true;
}


TreasureInteraction::~TreasureInteraction()
{}
