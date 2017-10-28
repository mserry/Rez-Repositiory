#include "FSM.h"
#include "IState.h"


FSM::FSM()
{
}


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
		m_states.push(m_states.top()->GetTransitionState());
	}
}

void FSM::End()
{

}
