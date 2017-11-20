#include "ChaseState.h"
#include "AIEntity.h"


ChaseState::ChaseState()  {}
ChaseState::~ChaseState() {}

EntityState ChaseState::GetStateName()
{
	return EntityState::k_chasing;
}

void ChaseState::OnUpdate(AIEntity* pOwnerEntity)
{
	if (pOwnerEntity->IsDead()) return;
	
	if(IsPlayerDetectedForEntity(pOwnerEntity)) 
	{
		Chase(pOwnerEntity);
	}
	else 
	{
		pOwnerEntity->HandleStateTransition(GetStateName());
	}
}

void ChaseState::OnEnter()
{
	m_isInit = true;
}

void ChaseState::OnExit()
{
}

void ChaseState::Chase(AIEntity* pThisEntity)
{

}
