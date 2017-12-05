#include "Tile.h"

Tile::Tile(): m_interaction(nullptr), m_state(TileState::k_ready), m_type(TileType::k_default) {}
Tile::Tile(int xPos, int yPos) : m_interaction(nullptr), m_state(TileState::k_ready), m_type(TileType::k_default), m_xPos(xPos), m_yPos(yPos) {}
Tile::~Tile() {}

void Tile::OnEnter(Entity* pEntity) {}

Tile::TileType Tile::GetType() const
{
	return k_default;
}

void Tile::SetState(TileState newState)
{
	m_state = newState;
}

Tile::TileState Tile::GetState() const
{
	return m_state;
}

int Tile::GetX() const
{
	return m_xPos;
}

int Tile::GetY() const
{
	return m_yPos;
}

void Tile::SetX(int x)
{
	m_xPos = x;
}

void Tile::SetY(int y)
{
	m_yPos = y;
}

