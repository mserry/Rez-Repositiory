#include "EvadeState.h"



EvadeState::EvadeState()
{
}


EvadeState::~EvadeState()
{
}

bool EvadeState::GetTransitionCondition()
{
	return false;
}

EntityState EvadeState::GetStateName()
{
	return EntityState::k_evading;
}

EntityState EvadeState::GetTransitionStateName()
{
	return EntityState::k_wandering;
}

void EvadeState::OnUpdate()
{
}

void EvadeState::OnEnter()
{
}

void EvadeState::OnExit()
{
}
