#pragma once
#include "Singleton.h"

class Renderer : Singleton<Renderer>
{

public:
	void Render() const;

private:
	Renderer();
	~Renderer();
};

