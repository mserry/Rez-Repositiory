#include "WanderState.h"
#include "World.h"
#include "AIEntity.h"
#include "Tile.h"

extern World* g_pWorld;

//Thurs 11/9

//TODO: add player is detected.
//TODO: add randomness for wandering.
//TODO: add new states (Finish imp.)
//TODO: figure out which state to push.

//TODO: testing & Fixes.

WanderState::WanderState()
{
}

WanderState::~WanderState()
{
}

void WanderState::OnUpdate(AIEntity* pThisEntity)
{
	if (pThisEntity->IsDead()) return;

	//fetch adj tiles.
	auto adjTiles = g_pWorld->GetAdjacentTiles(pThisEntity->GetX(), pThisEntity->GetY());

	for (Tile* tile : adjTiles)
	{
		
	}
}


void WanderState::OnEnter()
{
	m_isInit = true;
}

void WanderState::OnExit()
{

}

bool WanderState::IsPlayerDetectedForEntity(AIEntity* pOwnerEntity) const
{
	int entityXPos  = pOwnerEntity->GetX();
	int entityYPos  = pOwnerEntity->GetY();

	int worldHeight = g_pWorld->GetWorldHeight();
	int worldWidth  = g_pWorld->GetWorldWidth();

	int thisEntityTileIndex = (entityYPos + worldHeight) + entityXPos;
	int playerTileIndex     = g_pWorld->GetPlayerTileIndex();
	

	

}


