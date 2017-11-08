#pragma once

#include "IState.h"

class Tile;

class WanderState : public IState 
{
public:
	WanderState();
	virtual ~WanderState();

	virtual void OnUpdate(AIEntity* pOwnerEntity) override;
	virtual void OnEnter() override;
	virtual void OnExit() override;

	void MoveToAdjTile(AIEntity* pOwnerEntity, Tile* pAdjTile);

protected:
	virtual void ExecuteBehavior() override;

	virtual bool IsCorrectTile(Tile* pAdjTile);
	bool IsPlayerDetected() const;
};
