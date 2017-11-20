#include <iostream>

#include "Chaser.h"
#include "WanderState.h"
#include "ChaseState.h"


using std::cout;


Chaser::Chaser(int x, int y) : AIEntity(x,y)
{
	m_hitPoints = 5;
}

Chaser::~Chaser()
{
	delete m_pCurrentState;
	m_pCurrentState = nullptr;
}

void Chaser::HandleStateTransition(EntityState currentState)
{
	switch(currentState) 
	{
		case EntityState::k_wandering:
			SetState(new ChaseState);
			break;

		case EntityState::k_chasing:
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



