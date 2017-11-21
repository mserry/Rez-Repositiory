#include "StateUtils.h"
#include "AIEntity.h"
#include "World.h"

#include <cmath>

extern World* g_pWorld;


bool StateUtils::IsPlayerDetectedForEntity(AIEntity* pRequestingEntity)
{
	int entityXPos = pRequestingEntity->GetX();
	int entityYPos = pRequestingEntity->GetY();
	int playerXPos = g_pWorld->GetPlayerXPos();
	int playerYPos = g_pWorld->GetPlayerYPos();

	bool detectedTopLeft = (playerXPos >= (entityXPos - 5) && playerXPos <= (entityXPos - 1)) &&
		(playerYPos >= (entityYPos - 5) && playerYPos <= (entityYPos - 1));

	bool detectedTopRight = (playerXPos <= (entityXPos + 5) && playerXPos >= (entityXPos - 1)) &&
		(playerYPos >= (entityYPos - 5) && playerYPos <= (entityYPos - 1));

	bool detectedBottRight = (playerXPos <= (entityXPos + 5) && playerXPos >= (entityXPos - 1)) &&
		(playerYPos <= (entityYPos + 5) && playerYPos >= (entityYPos - 1));

	bool detectedBottLeft = (playerXPos >= (entityXPos - 5) && playerXPos <= (entityXPos - 1)) &&
		(playerYPos <= (entityYPos + 5) && playerYPos >= (entityYPos - 1));

	bool detectedTop = playerXPos == entityXPos && (playerYPos >= (entityYPos - 5) && playerYPos <= (entityYPos - 1));
	bool detectedRight = (playerXPos <= (entityXPos + 5) && playerXPos >= (entityXPos - 1)) && playerYPos == entityYPos;
	bool detectedLeft = (playerXPos >= (entityXPos - 5) && playerXPos <= (entityXPos - 1)) && playerYPos == entityYPos;
	bool detectedBott = playerXPos == entityXPos && (playerYPos <= (entityYPos + 5) && playerYPos >= (entityYPos - 1));


	return detectedTop || detectedBott || detectedLeft || detectedRight || detectedTopLeft || detectedTopRight || detectedBottLeft ||
		detectedBottRight;
}

std::vector<Tile*> StateUtils::GetTilesAroundEntity(int entityXPos, int entityYPos)
{
	return g_pWorld->GetAdjacentTiles(entityXPos, entityYPos);
}

float StateUtils::GetSqrDist(int x1, int y1, int x2, int y2)
{
	return pow((y2 - y1), 2.0) - pow((x2 - x1), 2.0);
}

int StateUtils::GetPlayerXPos()
{
	return g_pWorld->GetPlayerXPos();
}

int StateUtils::GetPlayerYPos()
{
	return g_pWorld->GetPlayerYPos();
}

StateUtils::StateUtils()
{
}


StateUtils::~StateUtils()
{
}
