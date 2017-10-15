#include "Entity.h"

Entity::Entity(): m_x(0), m_y(0), m_hitPoints(k_maxHitPoints), m_gold(0) {}

Entity::~Entity() {}


void Entity::AddGold(int amount)
{
	m_gold += amount;
}
