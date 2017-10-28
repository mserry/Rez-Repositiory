#pragma once
#include <stack>

class IState;

class FSM
{
public:
	FSM();
	~FSM();

	void Init();
	void Update();
	void End();

private:
	std::stack<IState*> m_states;
};

