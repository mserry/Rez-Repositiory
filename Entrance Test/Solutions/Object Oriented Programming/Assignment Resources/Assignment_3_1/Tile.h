// Tile.h
#pragma once
#include "TileInteraction.h"

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
		k_collected,
	};

	enum class TileType
	{
		k_floor,
		k_mimic,
		k_bomb,
		k_treasure,
		k_teleport,
		k_end,
		k_default,
	};

	virtual ~Tile(); // if your class is being used as a base class, it's best to have a virtual destructor
    virtual void Draw() = 0;
	virtual void OnEnter(Player* pPlayer);
	virtual TileType GetType() const;
	
	void SetState(State newState);
	State GetState() const;

protected:
	TileInteraction* m_interaction;
	State m_state;
	TileType m_type;
};

inline Tile::~Tile()
{
	delete m_interaction;
	m_interaction = nullptr;
}


inline void Tile::OnEnter(Player* pPlayer) {}

inline Tile::TileType Tile::GetType() const
{
	return TileType::k_default;
}

inline void Tile::SetState(State newState)
{
	m_state = newState;
}

inline Tile::State Tile::GetState() const
{
	return m_state;
}

