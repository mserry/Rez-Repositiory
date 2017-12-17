#include <iostream>

#include "Evader.h"
#include "EvadeState.h"
#include "WanderState.h"

using std::cout;

Evader::Evader(int x, int y) : AIEntity(x,y)
{
	m_hitPoints = 5;

	m_pCurrentState = new WanderState;
}

Evader::~Evader() 
{
	delete m_pCurrentState;
	m_pCurrentState = nullptr;
}

void Evader::Render()
{
	if (!IsDead())
		cout << "?";
	else
		cout << "~";
}

void Evader::TransitionToState(EntityStateName currentState)
{
	switch (currentState)
	{
		case EntityStateName::k_wandering:
			SetState(new WanderState);
			break;

		case EntityStateName::k_evading:
			SetState(new EvadeState);
			break;
	}
}
