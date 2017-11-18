#include "ChaseState.h"
#include "AIEntity.h"

ChaseState::ChaseState()
{
}

ChaseState::~ChaseState()
{
}

void ChaseState::OnUpdate(AIEntity* pThisEntity)
{
	if (pThisEntity->IsDead()) return;


}

void ChaseState::OnEnter()
{
}

void ChaseState::OnExit()
{
}

void ChaseState::TransitionToNextState()
{
}
