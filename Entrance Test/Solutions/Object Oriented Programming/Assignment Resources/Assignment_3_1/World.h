// World.h
#ifndef __WORLD_H__
#define __WORLD_H__

#include <utility>
#include <vector>

class Tile;
class Player;
class Entity;

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
	std::vector<Entity*> m_entities;
    bool m_gameOver;

public:
	World();
	~World();

    // initialization
    void Init(int width, int height);
    void CreatePlayer(int x = 0, int y = 0);
	void CreateEntity(int x, int y);
    void GenerateWorld();

    void Draw();
    void Update();

	//getters
	std::vector<Tile*> GetAdjacentTiles(int x, int y) const;
	std::vector<Entity*> GetEntities() const;
	int GetWorldWidth() const;
	int GetWorldHeight() const;
	Player* GetPlayer() const;
	Tile** GetTiles() const;

	// end
    void EndGame();
    bool IsGameOver() const { return m_gameOver; }

	
protected:
	void GenerateEntities();
};

#endif
