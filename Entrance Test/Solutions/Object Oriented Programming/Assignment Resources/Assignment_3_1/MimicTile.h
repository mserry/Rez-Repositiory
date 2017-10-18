// MimicTile.h
#ifndef __MIMICTILE_H__
#define __MIMICTILE_H__

#include "Tile.h"
#include "BombTile.h"

class MimicTile : public BombTile
{
public:
    MimicTile();
    virtual void Render() override;
    virtual void OnEnter(Entity* pEntity) override;
	virtual TileType GetType() const override;
};

#endif

