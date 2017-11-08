#include "WanderState.h"
#include "World.h"
#include "AIEntity.h"
#include "Tile.h"

extern World* g_pWorld;

//Thurs 11/9

//TODO: add new states (Finish imp.)
//TODO: add randomness for wandering.
//TODO: add player is detected.
//TODO: figure out which state to push.

//TODO: add X, Y pos for each tile.
//TODO: testing & Fixes.
//TODO: Brainstorm / Get started on Teleporter tiles.

//Friday 9/11 + Sat 10/11 -> Teleporter Tiles.

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
		ExecuteBehavior();
	}
}

void WanderState::MoveToAdjTile(AIEntity* pThisEntity, Tile* pAdjTile)
{	
	if (IsCorrectTile(pAdjTile)) 
	{
		pThisEntity->Move(pAdjTile->GetX(), pAdjTile->GetY());
	}
}

void WanderState::OnEnter()
{
	m_isInit = true;
}

void WanderState::OnExit()
{

}

void WanderState::ExecuteBehavior()
{
	if (!IsPlayerDetected()) 
	{
		// get random floor tile from adj tiles
		// move to it.
	}
	else 
	{
		//request state change.
	}
}

bool WanderState::IsCorrectTile(Tile* pAdjTile)
{
	return pAdjTile->GetType() == Tile::TileType::k_floor;
}

bool WanderState::IsPlayerDetected() const
{
	// get player from gworld
	// check if he's on any of the adj tiles (take tile as parameter).
	return false;
}
