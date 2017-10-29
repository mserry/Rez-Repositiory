#pragma once

#include <stack>

enum class EntityState;
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
	IState* GetNextState(EntityState stateName) const;
	void TransitionToNewState();

private:
	std::stack<IState*> m_states;
};

