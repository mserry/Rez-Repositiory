#pragma once
#include <vector>

class Tile;
class World;

class BlackBoard
{
	friend World;

public:
	static BlackBoard& GetInstance();

	int GetPlayerTileIndex();

	std::vector<Tile*> GetAdjTiles(int x, int y) const;

private:
	BlackBoard();
	~BlackBoard();

	void SetPlayerTileIndex(int index);

private:
	static int m_playerTileIndex;
};

