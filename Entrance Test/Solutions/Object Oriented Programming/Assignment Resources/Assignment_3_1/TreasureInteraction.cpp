#include "TreasureInteraction.h"
#include "Player.h"
#include "DamageInteraction.h"

TreasureInteraction::TreasureInteraction(Tile* powner, std::pair<int, int> treasureRange) :
DamageInteraction(powner,treasureRange), m_collectedTreasure(false)
{
	//TODO: Fix bool for collected treasure.

}


void TreasureInteraction::ExecuteOn(Player* pPlayer)
{
	if (m_collectedTreasure) return;

	pPlayer->AddGold(GetRndValInRange(m_range));
	m_collectedTreasure = true;

}


TreasureInteraction::~TreasureInteraction() {}