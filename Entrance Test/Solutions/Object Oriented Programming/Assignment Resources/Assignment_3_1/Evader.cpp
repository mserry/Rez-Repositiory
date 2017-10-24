#include <iostream>


#include "Evader.h"

using std::cout;

Evader::Evader(int x, int y) : Entity(x,y)
{
	m_hitPoints = 5;
}

Evader::~Evader() {}

void Evader::Render()
{
	if (!IsDead())
		cout << "?";
	else
		cout << "~";
}

bool Evader::Update()
{
	return false;
}

void Evader::Damage(int amount)
{
	if (m_hitPoints <= 0) return;

	m_hitPoints -= amount;
}

void Evader::Move(int xPos, int yPos)
{
	m_x += xPos;
	m_y += yPos;
}
