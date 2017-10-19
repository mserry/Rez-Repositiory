// Player.cpp
#include <iostream>

#include "Player.h"
#include "World.h"
#include "Tile.h"

using std::cout;

using TileState = Tile::State;

extern World* g_pWorld;

const int Entity::k_maxHitPoints = 10;
const int Player::k_baseScore = 1000;
const int Player::k_hitPointsWeight = 100;
const int Player::k_goldWeight = 10;
const int Player::k_moveCountWeight = 10;

Player::Player(int x, int y): m_moveCount(0), m_mimicMoves(3)  {}

void Player::RenderPlayerUi() const
{
    cout << "HP: " << m_hitPoints << "  Gold: " << m_gold << "  Move Count: " << m_moveCount << "  Score: " << CalculateScore() << "\n\n";
}

void Player::Render()
{
	if (!IsDead())
		cout << "@";
	else
		cout << "~";
}

bool Player::Update()
{
    if (IsDead())
        return false;

    return true;
}

void Player::Move(int deltaX, int deltaY)
{
    m_x += deltaX;
    m_y += deltaY;

    ++m_moveCount;
}

void Player::Damage(int amount)
{
    m_hitPoints -= amount;

    if (m_hitPoints < 0)
        m_hitPoints = 0;
}


int Player::CalculateScore() const
{
	return k_baseScore + (m_hitPoints * k_hitPointsWeight) + (m_gold * k_goldWeight) - (m_moveCount * k_moveCountWeight);
}

int Player::GetMimicMoves() const
{
	return m_mimicMoves;
}

int Player::GetMoveCount() const
{
	return m_moveCount;
}

void Player::DecrMimicMoves()
{
	--m_mimicMoves;
}

void Player::IncrementMoveCount()
{
	++m_moveCount;
}
