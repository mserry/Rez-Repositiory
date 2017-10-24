#pragma once
#include "Entity.h"


class Evader : public Entity
{
public:
	Evader();
	Evader(int x, int y);
	virtual ~Evader();

	virtual void Render() override;
	virtual bool Update() override;
	virtual void Damage(int amount) override;

protected:
	void Move(int xPos, int yPos) override;
};

