#pragma once
#include "AIEntity.h"


class Evader : public AIEntity
{
public:
	Evader(int x, int y);
	virtual ~Evader();

	virtual void Render() override;
};

