// EndTile.h
#ifndef __ENDTILE_H__
#define __ENDTILE_H__

#include "Tile.h"

class EndTile : public Tile
{
public:
    virtual void Render() override;
    virtual void OnEnter(Entity* pEntity) override;
	virtual TileType GetType() const override;
};

#endif

