#pragma once

class Entity;

class TileInteraction
{
public:
	TileInteraction();
	virtual ~TileInteraction();

	virtual void ExecuteOn(Entity* pEntity) = 0;
};

