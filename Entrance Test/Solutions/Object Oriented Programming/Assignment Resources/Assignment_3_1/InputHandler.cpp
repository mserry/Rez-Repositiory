#include <conio.h>
#include <iostream>

#include "InputHandler.h"
#include "World.h"
#include "Player.h"

extern World* g_pWorld;

//TODO: replace and refactor into world class.s
void InputHandler::ProcessInput()
{
	char input = _getch();

	//this is super ugly but i really dont know how else to do it in CPP :(
	switch (input)
	{
		case 'q':
			if (::g_pWorld) g_pWorld->EndGame();
			break;

		case 'w':
			if (g_pWorld && g_pWorld->GetPlayer()) g_pWorld->GetPlayer()->Move(0, -1);
			break;

		case 'a':
			if (g_pWorld && g_pWorld->GetPlayer()) g_pWorld->GetPlayer()->Move(-1, 0);
			break;

		case 's':
			if (g_pWorld && g_pWorld->GetPlayer()) g_pWorld->GetPlayer()->Move(0, 1);
			break;

		case 'd':
			if (g_pWorld && g_pWorld->GetPlayer()) g_pWorld->GetPlayer()->Move(1, 0);
			break;

		case 'e':
			if (g_pWorld) g_pWorld->DetectAdjacentMimics();
			break;

		default:
			std::cout << "Invalid input";
			break;
	}

}



InputHandler::InputHandler()  {}
InputHandler::~InputHandler() {}
