#pragma once
#include "Singleton.h"

class InputHandler : public Singleton<InputHandler>
{

public:
	void ProcessInput();

private:
	InputHandler();
	~InputHandler();

};

