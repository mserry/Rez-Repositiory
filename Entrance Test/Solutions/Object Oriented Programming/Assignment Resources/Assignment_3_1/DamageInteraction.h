#pragma once

#include <utility>
#include "TileInteraction.h"

class Entity;

class DamageInteraction : public TileInteraction
{
public:
	DamageInteraction(std::pair<int,int> dmgRange);
	virtual ~DamageInteraction();

	void ExecuteOn(Entity* pEntity) override;

protected:
	int GetRndValInRange(std::pair<int,int> range);


protected:
	std::pair<int,int> m_range;
};

