#include <iostream>

#include "Evader.h"

using std::cout;

Evader::Evader(int x, int y) : AIEntity(x,y)
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