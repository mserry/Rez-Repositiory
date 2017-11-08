#pragma once

#include "Entity.h"

class IState;

class AIEntity : public Entity
{
public:
	AIEntity();
	AIEntity(int x, int y);
	virtual ~AIEntity();

	virtual void Render() override = 0;
	virtual bool Update() override;
	virtual void Move(int xPos, int yPos) override;

	void ChangeState(IState* pNewState);
	
protected:
	IState* m_pCurrentState;
};

