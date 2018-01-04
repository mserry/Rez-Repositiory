#include <iostream>

#include "Chaser.h"
#include "WanderState.h"
#include "ChaseState.h"


using std::cout;


Chaser::Chaser(int x, int y) : AIEntity(x,y)
{
	m_hitPoints = 10;

	m_pCurrentState = new WanderState;
}

Chaser::~Chaser()
{
	delete m_pCurrentState;
	m_pCurrentState = nullptr;
}

void Chaser::TransitionToState(EntityStateName currentState)
{
	switch(currentState) 
	{
		case EntityStateName::k_wandering:
			SetState(new ChaseState);
		break;

		case EntityStateName::k_chasing:
			SetState(new WanderState);
		break;
	}
}

void Chaser::Render()
{
	if (!IsDead())
		cout << "!";
	else
		cout << "~";
}



