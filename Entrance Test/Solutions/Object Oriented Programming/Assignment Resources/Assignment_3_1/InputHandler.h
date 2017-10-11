#pragma once

class InputHandler
{

public:
	//someone said it's better to return it as a reference?
	static InputHandler& GetInstance();

	void ProcessInput();

private:
	InputHandler();
	~InputHandler();

};

