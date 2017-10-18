#include "Tile.h"
#include "TileInteraction.h"

Tile::~Tile()
{
	delete m_interaction;
	m_interaction = nullptr;
}

void Tile::OnEnter(Entity* pPlayer) {}

Tile::TileType Tile::GetType() const
{
	return TileType::k_default;
}

void Tile::SetState(State newState)
{
	m_state = newState;
}

Tile::State Tile::GetState() const
{
	return m_state;
}

