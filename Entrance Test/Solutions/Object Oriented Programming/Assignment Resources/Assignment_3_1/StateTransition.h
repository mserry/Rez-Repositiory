#pragma once

enum class EntityState;

class IState;

class StateTransition
{
public:
	StateTransition();
	virtual ~StateTransition();

	virtual bool TransitionCondition() = 0;
	virtual EntityState TransitionToState() = 0;
};

