#pragma once

class InputHandler
{
public:
	static InputHandler* GetInstance();

	void ProcessInput();

	int GetMoveCount() const;

private:
	InputHandler();
	~InputHandler();

	static InputHandler* m_instance;

	int m_moveCount;
};

