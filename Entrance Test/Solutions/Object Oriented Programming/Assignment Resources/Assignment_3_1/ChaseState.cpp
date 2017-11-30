#include <cmath>

#include "ChaseState.h"
#include "AIEntity.h"
#include "StateUtils.h"
#include "Tile.h"

ChaseState::ChaseState()  {}
ChaseState::~ChaseState() {}

EntityStateName ChaseState::GetStateName()
{
	return EntityStateName::k_chasing;
}

void ChaseState::OnUpdate(AIEntity* pOwnerEntity)
{
	if (pOwnerEntity->IsDead()) return;
	
	if(StateUtils::IsPlayerDetectedForEntity(pOwnerEntity)) 
	{
		Chase(pOwnerEntity);
	}
	else 
	{
		pOwnerEntity->HandleStateTransition(GetStateName());
	}
}

void ChaseState::OnEnter()
{
	m_isInit = true;
}

void ChaseState::OnExit() {}

void ChaseState::Chase(AIEntity* pThisEntity)
{
	int thisEntityXPos = pThisEntity->GetX();
	int thisEntityYPos = pThisEntity->GetY();

	int playerXPos = StateUtils::GetPlayerXPos();
	int playerYPos = StateUtils::GetPlayerYPos();
	auto adjTiles  = StateUtils::GetTilesAroundEntity(pThisEntity->GetX(), pThisEntity->GetY());

	if(adjTiles.size() > 0) 
	{
		float distToPlayer = 0.0f;
		int closestTileIndex = 0;

		for(size_t i = 0; i < adjTiles.size(); ++i) 
		{
			float tempDist = StateUtils::GetSqrDist(thisEntityXPos, playerXPos, thisEntityYPos, playerYPos);
			
			if(tempDist < distToPlayer) 
			{
				distToPlayer = tempDist;
				closestTileIndex = i;
			}
		}

		pThisEntity->Move(adjTiles[closestTileIndex]->GetX(), adjTiles[closestTileIndex]->GetY());
	}
}