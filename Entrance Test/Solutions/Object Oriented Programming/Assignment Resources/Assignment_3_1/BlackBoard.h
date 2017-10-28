#pragma once

class World;

class BlackBoard
{
	friend World;

public:
	static BlackBoard& GetInstance();

	int GetPlayerTileIndex();
	

private:
	BlackBoard();
	~BlackBoard();

	void SetPlayerTileIndex(int index);

private:
	static int m_playerTileIndex;
};

