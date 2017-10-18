#pragma once
#include "Singleton.h"


class InputHandler
{
	friend Singleton<InputHandler>;

public:
	void ProcessInput();

private:
	InputHandler();
	~InputHandler();
};

