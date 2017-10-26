#pragma once

#include "Entity.h"

enum class EntityState
{
	k_idle,
	k_wandering,
	k_chasing,
	k_evading,
	k_dead,
};

class AIEntity : public Entity
{
public:
	AIEntity();
	AIEntity(int x, int y);
	virtual ~AIEntity();

	virtual void Render() override = 0;
	virtual bool Update() override = 0;

	void SetState(EntityState newState);
	EntityState GetState() const;

protected:
	virtual void Move(int xPos, int yPos) override;

protected:
	EntityState m_state;
};

