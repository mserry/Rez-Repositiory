#pragma once
#include "Singleton.h"

class Renderer 
{
	friend Singleton<Renderer>;

public:
	void Render() const;

protected:
	void RenderUi() const;
	void RenderEntities() const;
	void RenderObjects() const;

private:
	Renderer();
	~Renderer();
};

