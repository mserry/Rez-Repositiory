#include "StateTransition.h"
#include "IState.h"


StateTransition::StateTransition(IState* startState, IState* endState)
{
	m_pStartState = startState;
	m_pEndState = endState;
}

StateTransition::~StateTransition() {}

bool StateTransition::IsValid() const
{
	return m_pStartState->GetTransitionCondition();
}

IState* StateTransition::GetStartState() const
{
	return m_pStartState;
}

IState* StateTransition::GetEndState() const
{
	return m_pEndState;
}
