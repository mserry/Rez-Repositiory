#pragma once

#include "IState.h"

class Tile;

class WanderState : public IState 
{
public:
	WanderState();
	virtual ~WanderState();

	virtual EntityState GetStateName() override;
	virtual void OnUpdate(AIEntity* pOwnerEntity) override;
	
	virtual void OnEnter() override;
	virtual void OnExit() override;

protected:
	bool IsPlayerDetectedForEntity(AIEntity* pOwnerEntity) const;

private:
	void Wander(AIEntity* pThisEntity);
};
