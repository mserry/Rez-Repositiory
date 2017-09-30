#pragma once

#include "DamageInteraction.h"

class TreasureInteraction : public DamageInteraction
{
public:
	TreasureInteraction(Tile* powner, std::pair<int,int> treasureRange);
	virtual ~TreasureInteraction();

	virtual void ExecuteOn(Player& player) override;

private:
	bool m_collectedTreasure;
};

