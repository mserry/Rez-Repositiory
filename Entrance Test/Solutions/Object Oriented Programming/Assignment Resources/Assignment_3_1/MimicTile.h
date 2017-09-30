// MimicTile.h
#ifndef __MIMICTILE_H__
#define __MIMICTILE_H__

#include "Tile.h"
#include "BombTile.h"

class MimicTile : public BombTile
{
public:
    MimicTile();
    virtual void Draw() override;
    virtual void OnEnter(Player* pPlayer) override;
};

#endif

