#pragma once

enum class EntityState
{
	k_idle,
	k_wandering,
	k_chasing,
	k_evading,
	k_dead,
};

class IState
{
public:
	IState();
	virtual ~IState();

	bool IsInit() const { return m_isInit; };

	virtual bool GetTransitionCondition() = 0;
	virtual EntityState GetStateName()    = 0;
	virtual EntityState GetTransitionStateName()  = 0;

	virtual void OnUpdate() = 0;
	virtual void OnEnter()  = 0;
	virtual void OnExit()   = 0;
	
protected:
	bool m_isInit;
};

inline IState::IState(): m_isInit(false) {}
inline IState::~IState() {}


