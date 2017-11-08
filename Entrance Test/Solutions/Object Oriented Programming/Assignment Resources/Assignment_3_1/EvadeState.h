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

protected:
	virtual void ExecuteBehavior() override;
	virtual bool IsCorrectTile(Tile* pAdjTile) override;
};

