// MimicTile.cpp
#include "MimicTile.h"
#include <iostream>

using std::cout;

MimicTile::MimicTile()
{
	m_state = State::k_hidden;
}

void MimicTile::Draw()
{
    switch (m_state)
    {
        case State::k_hidden:
            cout << "$";
            break;

        case State::k_active:
            cout << "*";
            break;

        case State::k_dead:
            cout << "#";
            break;

        default:
            cout << "ERROR: Invalid state in MimiTile";
            break;
    }
}

void MimicTile::OnEnter(Player* pPlayer)
{
	m_state = State::k_active;

	BombTile::OnEnter(pPlayer);
}

