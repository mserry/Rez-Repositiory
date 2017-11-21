#include "EvadeState.h"
#include "StateUtils.h"
#include "AIEntity.h"

EvadeState::EvadeState()  {}
EvadeState::~EvadeState() {}

EntityStateName EvadeState::GetStateName()
{
	return EntityStateName::k_evading;
}

void EvadeState::OnUpdate(AIEntity* pOwnerEntity)
{
	if(StateUtils::IsPlayerDetectedForEntity(pOwnerEntity)) 
	{
		Evade(pOwnerEntity);
	}
	else 
	{
		pOwnerEntity->HandleStateTransition(GetStateName());
	}
}

void EvadeState::OnEnter()
{
	m_isInit = true;
}

void EvadeState::OnExit()
{

}

void EvadeState::Evade(AIEntity* pThisEntity)
{
	//TODO: implemnt evade function.
	//TODO: implement X,Y Pos for tiles.
	//TODO: Debugging -> sudden doom.
	//TODO: debugging -> States.
	//TODO: Debugging -> behaviors.
}
