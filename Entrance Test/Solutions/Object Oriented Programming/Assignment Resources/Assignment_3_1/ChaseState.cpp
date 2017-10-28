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
