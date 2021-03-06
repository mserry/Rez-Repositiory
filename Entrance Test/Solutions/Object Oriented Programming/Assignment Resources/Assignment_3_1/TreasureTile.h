// TreasureTile.h
#ifndef __TREASURETILE_H__
#define __TREASURETILE_H__

#include "Tile.h"
#include <utility>

//TODO: refactor architecture !
class TreasureInteraction;

class TreasureTile : public Tile
{
    typedef std::pair<int, int> TreasureRange;
    static const TreasureRange s_treasureRange;

public:
    TreasureTile();
	virtual ~TreasureTile();

    virtual void Render() override;
    virtual void OnEnter(Entity* pEntity) override;
	virtual TileType GetType() const override;


private:

	TreasureInteraction* m_treasureInteraction;
};

#endif
