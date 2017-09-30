#pragma once

class Tile;
class Player;

class TileInteraction
{
public:
	virtual void ExecuteOn(Player& player) = 0;

protected:
	explicit TileInteraction(Tile* pOwner);
	~TileInteraction();

	Tile* mp_ownerTile;
};

