// Player.cpp
#include "Player.h"
#include <iostream>
#include "World.h"
#include "Tile.h"

using std::cout;

extern World* g_pWorld;

const int Entity::k_maxHitPoints = 10;
const int Player::k_baseScore = 1000;
const int Player::k_hitPointsWeight = 100;
const int Player::k_goldWeight = 10;
const int Player::k_moveCountWeight = 10;


Player::Player(int x, int y): m_moveCount(0), m_mimicMoves(3)  {}

void Player::DrawUi() const
{
    cout << "HP: " << m_hitPoints << "  Gold: " << m_gold << "  Move Count: " << m_moveCount << "  Score: " << CalculateScore() << "\n\n";
}

void Player::Draw()
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

void Player::DetectMimics()
{
	if (m_mimicMoves <= 0) return;

	auto adjacentTiles = g_pWorld->GetAdjacentTiles(m_x, m_y);

	for(int i = 0; i < adjacentTiles.size(); ++ i)
	{
		auto tile = adjacentTiles[i];
		if(tile->GetType() == Tile::TileType::k_mimic)
		{
			tile->SetState(Tile::State::k_revealed);
		}
	}

	--m_mimicMoves;
	++m_moveCount;
}

int Player::CalculateScore() const
{
    int score = k_baseScore + (m_hitPoints * k_hitPointsWeight) + (m_gold * k_goldWeight) - (m_moveCount * k_moveCountWeight);
    return score;
}
