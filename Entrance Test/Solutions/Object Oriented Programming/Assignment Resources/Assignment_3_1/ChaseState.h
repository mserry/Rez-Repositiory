#pragma once
#include "WanderState.h"

class ChaseState : public WanderState
{
public:
	ChaseState();
	virtual ~ChaseState();

	virtual void OnUpdate(AIEntity* pThisEntity) override;
	virtual void OnEnter() override;
	virtual void OnExit() override;

protected:
	virtual bool IsCorrectTile(Tile* pAdjTile) override;
};

