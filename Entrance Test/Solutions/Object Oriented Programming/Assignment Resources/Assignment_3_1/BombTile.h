// BombTile.h
#ifndef __BOMBTILE_H__
#define __BOMBTILE_H__

#include "Tile.h"
#include <utility>

class BombTile : public Tile
{
    typedef std::pair<int, int> DamageRange;

    static const DamageRange s_damageRange;

public:
    BombTile();
    virtual void Render() override;
    virtual void OnEnter(Entity* pEntity) override;
	virtual TileType GetType() const override;
};

#endif

