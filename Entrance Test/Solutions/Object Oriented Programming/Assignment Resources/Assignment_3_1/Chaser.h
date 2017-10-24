#pragma once

#include "Entity.h"


class Chaser : public Entity
{
public:
	Chaser();
	Chaser(int x, int y);
	virtual ~Chaser();

	virtual void Render() override;
	virtual bool Update() override;
	virtual void Damage(int amount) override;

protected:
	void Move(int xPos, int yPos) override;
};

