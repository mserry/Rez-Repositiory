#pragma once

#include "Entity.h"

class IState;
extern enum class EntityStateName;

class AIEntity : public Entity
{
public:
	AIEntity();
	AIEntity(int x, int y);
	virtual ~AIEntity();

	virtual void Render() override = 0;
	virtual void HandleStateTransition(EntityStateName currentState) = 0;

	virtual bool Update() override;
	virtual void Move(int xPos, int yPos) override;

protected:
	void SetState(IState* pNewState);

protected:
	IState* m_pCurrentState;
};

