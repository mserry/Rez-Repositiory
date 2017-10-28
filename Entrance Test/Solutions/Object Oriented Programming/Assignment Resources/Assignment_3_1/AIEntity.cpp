#include "AIEntity.h"
#include "FSM.h"

AIEntity::AIEntity(): m_entityFsm(nullptr) {}

AIEntity::AIEntity(int x, int y) : Entity(x, y), m_entityFsm(nullptr) {}

AIEntity::~AIEntity()
{
	//clearing state stack
	delete m_entityFsm;
}



const FSM& AIEntity::GetEntityStateMachine() const
{
	return *m_entityFsm;
}

void AIEntity::Move(int xPos, int yPos)
{
	m_x += xPos;
	m_y += yPos;
}