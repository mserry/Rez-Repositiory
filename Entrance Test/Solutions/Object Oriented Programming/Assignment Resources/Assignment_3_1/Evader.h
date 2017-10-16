#pragma once
#include "Entity.h"


class Evader : public Entity
{
public:
	Evader();
	~Evader();

	virtual void Draw() override;
	virtual bool Update() override;
	virtual void Damage(int amount) override;
};

