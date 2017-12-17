#include "EvadeState.h"
#include "StateUtils.h"
#include "AIEntity.h"
#include "Tile.h"

//TODO: Debugging -> sudden doom.
//TODO: debugging -> States.
//TODO: Debugging -> behaviors. 

EvadeState::EvadeState()  {}
EvadeState::~EvadeState() {}

EntityStateName EvadeState::GetStateName()
{
	return EntityStateName::k_evading;
}

void EvadeState::OnUpdate(AIEntity* pOwnerEntity)
{
	if(StateUtils::IsPlayerDetectedForEntity(pOwnerEntity)) 
	{
		Evade(pOwnerEntity);
	}
	else 
	{
		pOwnerEntity->TransitionToState(GetStateName());
	}
}

void EvadeState::OnEnter()
{
	m_isInit = true;
}

void EvadeState::OnExit()
{

}

bool EvadeState::ShouldExitState(AIEntity* pOwnerEntity)
{
	return StateUtils::IsPlayerDetectedForEntity(pOwnerEntity) != true;
}

//TODO: refactor, duplicate code between evade and chase, check some patterns.
void EvadeState::Evade(AIEntity* pThisEntity)
{
	int thisEntityXPos = pThisEntity->GetX();
	int thisEntityYPos = pThisEntity->GetY();

	int playerXPos = StateUtils::GetPlayerXPos();
	int playerYPos = StateUtils::GetPlayerYPos();
	std::vector<Tile*> adjTiles = StateUtils::GetTilesAroundEntity(pThisEntity->GetX(), pThisEntity->GetY());


	if (adjTiles.size() > 0)
	{
		float distToPlayer = 0.0f;
		int furthestTileIndex = 0;

		for (size_t i = 0; i < adjTiles.size(); ++i)
		{
			float tempDist = StateUtils::GetSqrDist(thisEntityXPos, playerXPos, thisEntityYPos, playerYPos);

			if (tempDist > distToPlayer)
			{
				distToPlayer = tempDist;
				furthestTileIndex = i;
			}
		}

		pThisEntity->Move(adjTiles[furthestTileIndex]->GetX(), adjTiles[furthestTileIndex]->GetY());
	}
}
