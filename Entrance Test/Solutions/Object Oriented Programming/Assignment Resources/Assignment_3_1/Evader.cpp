#include "Evader.h"
#include <iostream>

using std::cout;


Evader::Evader() {}
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
