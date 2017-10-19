// Tile.h
#pragma once

class TileInteraction;
class Entity;

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
		k_ready,
	};

	enum TileType
	{
		k_floor,
		k_mimic,
		k_bomb,
		k_treasure,
		k_teleport,
		k_end,
		k_default,
	};

	Tile();
	virtual ~Tile() = 0;

    virtual void Render() = 0;

	virtual void OnEnter(Entity* pEntity);
	virtual TileType GetType() const;
	
	//getters and setters.
	void SetState(State newState);
	State GetState() const;


protected:
	TileInteraction* m_interaction;
	State m_state;
	TileType m_type;
};
