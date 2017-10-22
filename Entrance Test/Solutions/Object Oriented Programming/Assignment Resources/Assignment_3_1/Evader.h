#pragma once
#include "Entity.h"


class Evader : public Entity
{
public:
	Evader();
	virtual ~Evader();

	virtual void Render() override;
	virtual bool Update() override;
	virtual void Damage(int amount) override;
};

