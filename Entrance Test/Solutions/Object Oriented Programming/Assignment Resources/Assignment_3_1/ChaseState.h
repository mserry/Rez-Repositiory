#pragma once
#include "WanderState.h"
class ChaseState : public WanderState
{
public:
	ChaseState();
	~ChaseState();

	virtual EntityState GetStateName() override;
	virtual void OnUpdate(AIEntity* pOwnerEntity) override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

protected:
	void Chase(AIEntity* pThisEntity);
};

