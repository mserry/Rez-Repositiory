#include "BlackBoard.h"
#include "World.h"

extern World* g_pWorld;

BlackBoard::BlackBoard() {}
BlackBoard::~BlackBoard() {}

BlackBoard& BlackBoard::GetInstance()
{
	static BlackBoard instance;

	return instance;
}

int BlackBoard::GetPlayerTileIndex()
{
	return m_playerTileIndex;
}

std::vector<Tile*> BlackBoard::GetAdjTiles(int x, int y) const
{
	return g_pWorld->GetAdjacentTiles(x, y);
}

void BlackBoard::SetPlayerTileIndex(int index)
{
	m_playerTileIndex = index;
}
