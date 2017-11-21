#pragma once

#include <vector>

class AIEntity;
class Tile;

//a wrapper around the world object that is accessed by state to retrieve world information. 
class StateUtils
{
public:
	static bool IsPlayerDetectedForEntity(AIEntity* pRequestingEntity);

	static std::vector<Tile*> GetTilesAroundEntity(int entityXPos, int entityYPos);
	static float GetSqrDist(int x1, int y1, int x2, int y2);
	
	static int GetPlayerXPos();
	static int GetPlayerYPos();

private:
	StateUtils() = delete;
	~StateUtils() = delete;
};

