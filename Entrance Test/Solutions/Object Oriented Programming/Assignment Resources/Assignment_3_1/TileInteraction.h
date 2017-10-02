#pragma once

class Tile;
class Player;

class TileInteraction
{
public:
	virtual void ExecuteOn(Player* pPlayer) = 0;
	virtual ~TileInteraction();

protected:
	explicit TileInteraction(Tile* pOwner);
	
	Tile* mp_ownerTile;
};

