// BombTile.cpp
#include "BombTile.h"
#include "Player.h"
#include <iostream>
#include "DamageInteraction.h"

const BombTile::DamageRange BombTile::s_damageRange(3, 6);

BombTile::BombTile()
{
	m_state = State::k_active;
	m_interaction = new DamageInteraction(this,s_damageRange);
}

void BombTile::Draw()
{
    if (m_state == State::k_active)
        std::cout << "*";
    else
        std::cout << "#";
}

void BombTile::OnEnter(Player* pPlayer)
{
	m_interaction->ExecuteOn(*pPlayer);
	m_state = State::k_dead;
}



