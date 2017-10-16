// Player.h
#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "InputHandler.h"
#include "Entity.h"

class Player : public Entity
{
	friend InputHandler;

	static const int k_baseScore;
	static const int k_hitPointsWeight, k_goldWeight, k_moveCountWeight;

public:
    Player(int x, int y);

    virtual void Draw() override;
	virtual bool Update() override;
	virtual void Damage(int amount) override;
	
	void DetectMimics();

	void DrawUi() const;
    int CalculateScore() const;

protected:
	virtual void Move(int xPos, int yPos) override;


private:
	int m_moveCount;
	int m_mimicMoves;
};

#endif
