#pragma once

#include "AIEntity.h"


class Chaser : public AIEntity
{
public:
	Chaser(int x, int y);
	virtual ~Chaser();

	virtual void HandleStateTransition(EntityStateName currentState) override;
	virtual void Render() override;
};

