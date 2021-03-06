#pragma once

enum class EntityStateName
{
	k_wandering,
	k_chasing,
	k_evading,
};

class AIEntity;

class IState
{
public:
	IState();
	virtual ~IState();

	bool IsInit() const { return m_isInit; };

	virtual EntityStateName GetStateName() = 0;
	virtual void OnUpdate(AIEntity* pOwnerEntity) = 0;
	virtual void OnEnter()  = 0;
	virtual void OnExit()   = 0;

	virtual bool ShouldExitState(AIEntity* pOwnerEntity) = 0;

protected:
	bool m_isInit;
};

inline IState::IState(): m_isInit(false) {}
inline IState::~IState() {}


