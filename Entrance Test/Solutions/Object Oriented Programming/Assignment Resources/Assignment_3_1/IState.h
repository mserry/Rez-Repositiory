#pragma once

class IState
{	
	virtual void OnUpdate() = 0;
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;

protected:
	IState() = delete;
	~IState() = delete;
};

