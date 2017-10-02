#include "TileInteraction.h"
#include "Tile.h"

TileInteraction::TileInteraction(Tile* pOwner): mp_ownerTile(pOwner)
{
}

TileInteraction::~TileInteraction()
{
	delete mp_ownerTile;
	mp_ownerTile = nullptr;
}
