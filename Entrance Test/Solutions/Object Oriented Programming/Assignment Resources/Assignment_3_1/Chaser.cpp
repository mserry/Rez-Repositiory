#include "Chaser.h"
#include <iostream>

using std::cout;

Chaser::Chaser() {}

Chaser::Chaser(int x, int y) : AIEntity(x,y)
{
	m_hitPoints = 5;
}

Chaser::~Chaser()
{
	
}

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



