#include <conio.h>
#include <iostream>

#include "InputHandler.h"


InputHandler* InputHandler::GetInstance()
{
	if(!m_instance)
	{
		m_instance = new InputHandler();
	}

	return m_instance;
}

void InputHandler::ProcessInput()
{
	char input = _getch();

	switch (input)
	{
		case 'q':
			//return false;  // quitting

		case 'w':
			//Move(0, -1);
			break;

		case 'a':
			//Move(-1, 0);
			break;

		case 's':
			//Move(0, 1);
			break;

		case 'd':
			//Move(1, 0);
			break;

		case 'e':

			break;

		default:
			std::cout << "Invalid input";
			break;
	}

}

int InputHandler::GetMoveCount() const
{
	return m_moveCount;
}

InputHandler::InputHandler(): m_moveCount(0) {}


InputHandler::~InputHandler()
{
}
