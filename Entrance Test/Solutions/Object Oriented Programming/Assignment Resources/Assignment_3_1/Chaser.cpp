#include "Chaser.h"
#include <iostream>

using std::cout;

Chaser::Chaser() {}

Chaser::Chaser(int x, int y) : Entity(x,y)
{
	m_hitPoints = 5;
}

Chaser::~Chaser() {}

void Chaser::Render()
{
	if (!IsDead())
		cout << "!";
	else
		cout << "~";
}

bool Chaser::Update()
{
	return false;
}

void Chaser::Damage(int amount)
{
	if (m_hitPoints <= 0) return;

	m_hitPoints -= amount;
}

void Chaser::Move(int xPos, int yPos)
{
	m_x += xPos;
	m_y += yPos;
}
