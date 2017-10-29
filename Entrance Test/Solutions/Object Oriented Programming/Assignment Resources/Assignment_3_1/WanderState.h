#pragma once
#include "IState.h"

class WanderState : public IState
{
public:
	WanderState();
	virtual ~WanderState();

	//getters
	bool GetTransitionCondition()        override;
	EntityState GetStateName()           override;
	EntityState GetTransitionStateName() override;

	//methods
	void OnUpdate()  override;
	void OnEnter ()  override;
	void OnExit  ()  override;
};

