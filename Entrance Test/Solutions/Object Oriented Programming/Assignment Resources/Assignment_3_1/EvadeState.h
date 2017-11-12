#pragma once
#include "ChaseState.h"

class EvadeState : public ChaseState
{
public:
	EvadeState();
	virtual ~EvadeState();

	virtual void OnUpdate(AIEntity* pThisEntity) override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
};

