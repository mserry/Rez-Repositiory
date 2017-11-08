#include "AIEntity.h"
#include "IState.h"

AIEntity::AIEntity(): m_pCurrentState(nullptr) {}

AIEntity::AIEntity(int x, int y) : Entity(x, y), m_pCurrentState(nullptr) {}

AIEntity::~AIEntity()
{
	delete m_pCurrentState;
	m_pCurrentState = nullptr;
}

bool AIEntity::Update()
{
	if (!m_pCurrentState->IsInit()) 
	{
		m_pCurrentState->OnEnter();
	}

	m_pCurrentState->OnUpdate(this);

	if (IsDead())
		m_pCurrentState->OnExit();

	return IsDead();
}

void AIEntity::ChangeState(IState* pNewState)
{
	delete m_pCurrentState;

	m_pCurrentState = nullptr;
	m_pCurrentState = pNewState;
}

void AIEntity::Move(int xPos, int yPos)
{
	m_x += xPos;
	m_y += yPos;
}