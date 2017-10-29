#include "FSM.h"
#include "IState.h"

#include "WanderState.h"
#include "ChaseState.h"
#include "EvadeState.h"


FSM::FSM() {}

FSM::~FSM()
{
	if (m_states.size() > 0)
	{
		while (!m_states.empty())
		{
			delete m_states.top();
			m_states.pop();
		}
	}
}

void FSM::Init()
{

}

void FSM::TransitionToNewState()
{
	auto nextState = GetNextState(m_states.top()->GetTransitionStateName());

	if(nextState != nullptr)
	{
		m_states.pop();
		m_states.push(nextState);
	}
}

void FSM::Update()
{
	if (m_states.empty()) return;

	if (!m_states.top()->IsInit())
	{
		m_states.top()->OnEnter();
	}

	if (!m_states.top()->GetTransitionCondition())
	{
		m_states.top()->OnUpdate();
	}
	else
	{
		m_states.top()->OnExit();
		
		TransitionToNewState();
	}
}

void FSM::End()
{

}


IState* FSM::GetNextState(EntityState stateName) const
{
	switch (stateName)
	{
		case EntityState::k_wandering:
			return new WanderState;

		case EntityState::k_chasing:
			return new ChaseState;
		
		case EntityState::k_evading: 
			return new EvadeState;
	}

	return nullptr;
}
