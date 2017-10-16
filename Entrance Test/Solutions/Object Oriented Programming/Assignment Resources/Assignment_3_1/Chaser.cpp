#include "Chaser.h"
#include <iostream>

using std::cout;

Chaser::Chaser()
{
}

Chaser::~Chaser()
{
}


void Chaser::Draw()
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
