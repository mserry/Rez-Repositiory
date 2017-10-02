#pragma once

class Tile;
class Player;

class TileInteraction
{
public:
	virtual void ExecuteOn(Player& player) = 0;
	virtual ~TileInteraction();

protected:
	explicit TileInteraction(Tile* pOwner);
	
	Tile* mp_ownerTile;
};

