#include "AIEntity.h"
#include "IState.h"

AIEntity::AIEntity(): m_pCurrentState(nullptr) {}
AIEntity::AIEntity(int x, int y) : Entity(x, y), m_pCurrentState(nullptr) {}
AIEntity::~AIEntity() {}


bool AIEntity::Update()
{
	if (!m_pCurrentState->IsInit()) 
	{
		m_pCurrentState->OnEnter();
	}

	m_pCurrentState->OnUpdate(this);

	//exit state.
	if(m_pCurrentState->ShouldExitState(this))
	{
		m_pCurrentState->OnExit();
		TransitionToState(m_pCurrentState->GetStateName());
	}

	return IsDead();
}

void AIEntity::Move(int xPos, int yPos)
{
	m_x += xPos;
	m_y += yPos;
}

void AIEntity::SetState(IState* pNewState)
{
	delete m_pCurrentState;
	m_pCurrentState = nullptr;

	m_pCurrentState = pNewState;
}
