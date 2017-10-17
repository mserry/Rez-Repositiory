#pragma once
#include "Entity.h"


class Chaser : public Entity
{
public:
	Chaser();
	~Chaser();

	virtual void Render() override;
	virtual bool Update() override;
	virtual void Damage(int amount) override;
};

