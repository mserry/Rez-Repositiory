#pragma once

class IState
{
public:
	IState();
	virtual ~IState();

	virtual void OnUpdate() = 0;
	virtual void OnEnter()  = 0;
	virtual void OnExit()   = 0;
};

inline IState::IState() {}
inline IState::~IState() {}

