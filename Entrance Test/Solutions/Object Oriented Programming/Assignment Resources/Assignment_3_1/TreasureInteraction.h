#pragma once

#include "DamageInteraction.h"

class TreasureInteraction : public DamageInteraction
{
public:
	TreasureInteraction(Tile* powner, std::pair<int,int> treasureRange);
	virtual ~TreasureInteraction();

	virtual void ExecuteOn(Player* pPlayer) override;

private:
	bool m_collectedTreasure;
};

