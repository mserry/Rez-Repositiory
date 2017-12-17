#include "WanderState.h"
#include "AIEntity.h"
#include "Tile.h"
#include "StateUtils.h"


WanderState::WanderState() {}
WanderState::~WanderState(){}


void WanderState::OnEnter()
{
	m_isInit = true;
}

EntityStateName WanderState::GetStateName()
{
	return EntityStateName::k_wandering;
}

void WanderState::OnUpdate(AIEntity* pThisEntity)
{
	if (pThisEntity->IsDead()) return;

	if (!StateUtils::IsPlayerDetectedForEntity(pThisEntity)) 
	{
		Wander(pThisEntity);
	}
}


void WanderState::OnExit() {}

bool WanderState::ShouldExitState(AIEntity* pOwnerEntity)
{
	return StateUtils::IsPlayerDetectedForEntity(pOwnerEntity);
}

void WanderState::Wander(AIEntity* pThisEntity)
{
	auto adjTiles = StateUtils::GetTilesAroundEntity(pThisEntity->GetX(), pThisEntity->GetY());
	std::vector<int> floorTileIndices;

	for (int i = 0; i < adjTiles.size(); ++i) 
	{
		if (adjTiles[i]->GetType() != Tile::TileType::k_floor) continue;

		floorTileIndices.push_back(i);
	}

	int selectedIndex = rand() % floorTileIndices.size();
	pThisEntity->Move(adjTiles[selectedIndex]->GetX(), adjTiles[selectedIndex]->GetY());
}


