#include <iostream>

#include "Chaser.h"


using std::cout;


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



