// Player.h
#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "InputHandler.h"

class Player
{
	friend InputHandler;

public:
    Player(int x, int y);

    void Draw() const;  // assumes the cursor is at the right place
    void DrawUi() const;
    bool Update();

    int GetX() const { return m_x; }
    int GetY() const { return m_y; }

    bool IsDead() const { return (m_hitPoints <= 0); }
    void Damage(int amount);
    void Kill() { m_hitPoints = 0; }
	void DetectMimics();

    void AddGold(int amount);

    int CalculateScore() const;

private:
    void Move(int deltaX, int deltaY);

private:
	static const int k_maxHitPoints;

	static const int k_baseScore;
	static const int k_hitPointsWeight, k_goldWeight, k_moveCountWeight;

	int m_x, m_y;
	int m_hitPoints;
	int m_gold;
	int m_moveCount;
};

#endif
