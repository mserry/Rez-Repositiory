#pragma once

#include "DamageInteraction.h"

class TreasureInteraction : public DamageInteraction
{
public:
	TreasureInteraction(std::pair<int,int> treasureRange);
	virtual ~TreasureInteraction();

	virtual void ExecuteOn(Entity* pEntity) override;
};

