// World.h
#ifndef __WORLD_H__
#define __WORLD_H__

#include <utility>
#include "InputHandler.h"

class Tile;
class Player;

class World
{
    enum class TileType
    {
        k_floor,
        k_bomb,
        k_treasure,
        k_mimic,
        k_numTiles,
    };

    typedef std::pair<int, TileType> TileProbability;

    static const TileProbability s_tileProbabilities[(int)TileType::k_numTiles];
    
    int m_width, m_height;
    Tile** m_ppGrid;
    Player* m_pPlayer;
	InputHandler* m_pInputHandler;
    bool m_gameOver;

public:
	World();
	~World();

    // initialization
    void Init(int width, int height);
    void CreatePlayer(int x = 0, int y = 0);
    void GenerateWorld();

    // update
    void Draw();
    void Update();

	Tile* GetAdjacentTiles(int x, int y);

	// end
    void EndGame();
    bool IsGameOver() const { return m_gameOver; }

	//getters
	Player* GetPlayer() const;
};

#endif
