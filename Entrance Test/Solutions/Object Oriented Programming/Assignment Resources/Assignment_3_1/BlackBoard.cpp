#include "BlackBoard.h"


BlackBoard& BlackBoard::GetInstance()
{
	static BlackBoard instance;

	return instance;
}

int BlackBoard::GetPlayerTileIndex()
{
	return m_playerTileIndex;
}

BlackBoard::BlackBoard() {}


BlackBoard::~BlackBoard()
{
}

void BlackBoard::SetPlayerTileIndex(int index)
{
	m_playerTileIndex = index;
}
