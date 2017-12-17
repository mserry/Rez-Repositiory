#pragma once
#include "IState.h"

class ChaseState : public IState
{
public:
	ChaseState();
	virtual ~ChaseState();

	virtual EntityStateName GetStateName() override;
	virtual void OnUpdate(AIEntity* pOwnerEntity) override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

	bool ShouldExitState(AIEntity* pOwnerEntity) override;

private:
	void Chase(AIEntity* pThisEntity);
};

