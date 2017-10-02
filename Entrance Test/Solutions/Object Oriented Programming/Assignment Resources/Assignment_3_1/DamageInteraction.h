#pragma once

#include "TileInteraction.h"
#include <utility>

class DamageInteraction : public TileInteraction
{
public:
	DamageInteraction(Tile* powner, std::pair<int,int> dmgRange);

	void ExecuteOn(Player* pPlayer) override;

protected:
	int GetRndValInRange(std::pair<int,int> range);


protected:
	std::pair<int,int> m_range;
};

