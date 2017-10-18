// FloorTile.h
#ifndef __FLOORTILE_H__
#define __FLOORTILE_H__

#include "Tile.h"

class FloorTile : public Tile
{
public:
    virtual void Render() override;
	virtual TileType GetType() const override;
};

#endif
