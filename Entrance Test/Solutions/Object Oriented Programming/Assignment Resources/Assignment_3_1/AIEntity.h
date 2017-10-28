#pragma once

#include "Entity.h"

class FSM;

class AIEntity : public Entity
{
public:
	AIEntity();
	AIEntity(int x, int y);
	virtual ~AIEntity();

	virtual void Render() override = 0;
	virtual bool Update() override = 0;

	const FSM& GetEntityStateMachine() const;

protected:
	virtual void Move(int xPos, int yPos) override;

protected:
	FSM* m_entityFsm;
};

