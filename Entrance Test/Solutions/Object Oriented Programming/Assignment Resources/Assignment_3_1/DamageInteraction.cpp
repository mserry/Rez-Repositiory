#include "DamageInteraction.h"
#include "Entity.h"

DamageInteraction::DamageInteraction(std::pair<int,int> dmgRange) : m_range(dmgRange) {}
DamageInteraction::~DamageInteraction() {}

void DamageInteraction::ExecuteOn(Entity* pEntity)
{
	pEntity->Damage(GetRndValInRange(m_range));
}

int DamageInteraction::GetRndValInRange(std::pair<int,int> range)
{
	return (rand() % range.second - range.first) + range.first;
}
