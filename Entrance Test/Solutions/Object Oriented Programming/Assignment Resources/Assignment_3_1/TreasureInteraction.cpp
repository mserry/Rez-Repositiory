#include "TreasureInteraction.h"
#include "DamageInteraction.h"
#include "Entity.h"

TreasureInteraction::TreasureInteraction(std::pair<int, int> treasureRange): DamageInteraction(treasureRange) {}
TreasureInteraction::~TreasureInteraction() {}


void TreasureInteraction::ExecuteOn(Entity* pEntity)
{
	pEntity->AddGold(GetRndValInRange(m_range));
}

