#pragma once
#include "Entity.h"


class Evader : public Entity
{
public:
	Evader(int x, int y);
	virtual ~Evader();

	virtual void Render() override;
};

