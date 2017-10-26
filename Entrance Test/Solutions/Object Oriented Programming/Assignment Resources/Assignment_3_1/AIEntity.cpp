#include "AIEntity.h"


AIEntity::AIEntity(): m_state(EntityState::k_idle) {}
AIEntity::AIEntity(int x, int y) : Entity(x, y), m_state(EntityState::k_idle) {}
AIEntity::~AIEntity() {}

void AIEntity::SetState(EntityState newState)
{
	m_state = newState;
}

EntityState AIEntity::GetState() const
{
	return m_state;
}

void AIEntity::Move(int xPos, int yPos)
{
	m_x += xPos;
	m_y += yPos;
}