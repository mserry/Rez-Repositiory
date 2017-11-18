#include "WanderState.h"
#include "World.h"
#include "AIEntity.h"
#include "Tile.h"

extern World* g_pWorld;

//Thurs 11/9

//TODO: add new states (Finish imp.)
//TODO: add x, y pos for tiles.
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

	if (!IsPlayerDetectedForEntity(pThisEntity)) 
	{
		Wander(pThisEntity);
	}
	else 
	{
		TransitionToNextState();
	}
}

void WanderState::Wander(AIEntity* pThisEntity)
{
	auto adjTiles = g_pWorld->GetAdjacentTiles(pThisEntity->GetX(), pThisEntity->GetY());
	std::vector<int> floorTiles;

	for (int i = 0; i < adjTiles.size(); ++i) 
	{
		if (adjTiles[i]->GetType() != Tile::TileType::k_floor) continue;

		floorTiles.push_back(i);
	}

	int selectedIndex = rand() % floorTiles.size();
	pThisEntity->Move(adjTiles[selectedIndex]->GetX(), adjTiles[selectedIndex]->GetY());
}


void WanderState::OnEnter()
{
	m_isInit = true;
}

void WanderState::OnExit()
{

}

//explaination in document. 
bool WanderState::IsPlayerDetectedForEntity(AIEntity* pOwnerEntity) const
{
	int entityXPos  = pOwnerEntity->GetX();
	int entityYPos  = pOwnerEntity->GetY();
	int playerXPos  = g_pWorld->GetPlayerXPos();
	int playerYPos  = g_pWorld->GetPlayerYPos();
	
	bool detectedTopLeft   = (playerXPos >= (entityXPos - 5) && playerXPos <= (entityXPos - 1)) &&
		(playerYPos >= (entityYPos - 5) && playerYPos <= (entityYPos - 1));

	bool detectedTopRight  = (playerXPos <= (entityXPos + 5) && playerXPos >= (entityXPos - 1)) &&
		(playerYPos >= (entityYPos - 5) && playerYPos <= (entityYPos - 1));

	bool detectedBottRight = (playerXPos <= (entityXPos + 5) && playerXPos >= (entityXPos - 1)) &&
		(playerYPos <= (entityYPos + 5) && playerYPos >= (entityYPos - 1));

	bool detectedBottLeft = (playerXPos >= (entityXPos - 5) && playerXPos <= (entityXPos - 1)) &&
		(playerYPos <= (entityYPos + 5) && playerYPos >= (entityYPos - 1));

	bool detectedTop   = playerXPos == entityXPos && (playerYPos >= (entityYPos - 5) && playerYPos <= (entityYPos - 1));
	bool detectedRight = (playerXPos <= (entityXPos + 5) && playerXPos >= (entityXPos - 1)) && playerYPos == entityYPos;
	bool detectedLeft  = (playerXPos >= (entityXPos - 5) && playerXPos <= (entityXPos - 1))  && playerYPos == entityYPos;
	bool detectedBott  = playerXPos == entityXPos && (playerYPos <= (entityYPos + 5) && playerYPos >= (entityYPos - 1));


	return detectedTop || detectedBott || detectedLeft || detectedRight || detectedTopLeft || detectedTopRight || detectedBottLeft ||
		detectedBottRight;
}


