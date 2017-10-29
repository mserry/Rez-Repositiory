#include "ChaseState.h"

ChaseState::ChaseState() {}

ChaseState::~ChaseState() {}

EntityState ChaseState::GetStateName()
{
	return EntityState::k_chasing;
}

void ChaseState::OnUpdate()
{

}

void ChaseState::OnEnter()
{

}

void ChaseState::OnExit()
{

}

bool ChaseState::GetTransitionCondition()
{
	return false;
}

EntityState ChaseState::GetTransitionStateName()
{
	return EntityState::k_wandering;
}
