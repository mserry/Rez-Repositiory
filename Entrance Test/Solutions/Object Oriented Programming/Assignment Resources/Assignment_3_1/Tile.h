// Tile.h
#ifndef __TILE_H__
#define __TILE_H__

class TileInteraction;
class Player;

class Tile
{
public:
	enum class State
	{
		k_active,
		k_dead,
		k_hidden,
		k_revealed,
	};

    virtual ~Tile() { }  // if your class is being used as a base class, it's best to have a virtual destructor
    virtual void Draw() = 0;
    virtual void OnEnter(Player* pPlayer) { }

protected:
	TileInteraction* m_interaction;
	State m_state;
};

#endif

