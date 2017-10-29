#pragma once

enum class EntityState;

class IState;

class StateTransition
{
public:
	StateTransition(IState* startState, IState* endState);
	virtual ~StateTransition();

	bool IsValid() const;

	IState* GetStartState() const;
	IState* GetEndState() const;

private:
	IState* m_pStartState;
	IState* m_pEndState;
};

