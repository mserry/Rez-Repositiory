// Tile.h
#pragma once

class TileInteraction;
class Entity;

class Tile
{
public:
	enum class TileState
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
	virtual ~Tile();

    virtual void Render() = 0;

	virtual void OnEnter(Entity* pEntity) {}
	virtual TileType GetType() const;
	
	//getters and setters.
	void SetState(TileState newState);
	TileState GetState() const;

	int GetX() const;
	int GetY() const;

	void SetX(int x);
	void SetY(int y);


protected:
	TileState m_state;
	TileType m_type;

	int m_xPos;
	int m_yPos;
};
