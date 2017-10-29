#pragma once
#include "IState.h"

class EvadeState : public IState
{
public:
	EvadeState();
	virtual ~EvadeState();
	bool GetTransitionCondition() override;
	EntityState GetStateName() override;
	EntityState GetTransitionStateName() override;
	void OnUpdate() override;
	void OnEnter() override;
	void OnExit() override;
};

