#pragma once

template <typename T>
class Singleton<T>;

class InputHandler
{
	friend Singleton<InputHandler>;

public:
	void ProcessInput();

private:
	InputHandler();
	~InputHandler();
};

