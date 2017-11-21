#pragma once
#include "IState.h"

class EvadeState : public IState
{
public:
	EvadeState();
	virtual ~EvadeState();

	virtual EntityStateName GetStateName() override;
	virtual void OnUpdate(AIEntity* pOwnerEntity) override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

private:
	void Evade(AIEntity* pThisEntity);
};

