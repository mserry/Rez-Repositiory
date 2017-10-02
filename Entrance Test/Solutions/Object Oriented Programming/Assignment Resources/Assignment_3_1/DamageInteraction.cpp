#include "DamageInteraction.h"
#include "Player.h"

DamageInteraction::DamageInteraction(Tile* powner, std::pair<int,int> dmgRange) : TileInteraction(powner)
{
	m_range = dmgRange;
}

void DamageInteraction::ExecuteOn(Player* pPlayer)
{
	pPlayer->Damage(GetRndValInRange(m_range));
}

int DamageInteraction::GetRndValInRange(std::pair<int,int> range)
{
	return (rand() % range.second - range.first) + range.first;
}
