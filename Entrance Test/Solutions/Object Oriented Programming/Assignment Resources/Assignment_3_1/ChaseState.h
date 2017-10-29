#pragma once

#include "IState.h"

class ChaseState : public IState
{
public:
	ChaseState();
	virtual ~ChaseState();

	virtual EntityState GetStateName() override;
	virtual void OnUpdate() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
	bool GetTransitionCondition() override;
	EntityState GetTransitionStateName() override;
};

