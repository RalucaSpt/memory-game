#pragma once
#include <vector>
#include "IGameListener.h"

enum UserChoice : signed char
{
	NONE = 0,
	STARTGAME = 1,
	MAKEMOVE = 2
};
class Observable
{
public:
	void AddListener(IGameListener* listener);
	void RemoveListener(IGameListener* listener);

	void NotifyAll(UserChoice choice);

private:
	std::vector<IGameListener*> m_listeners;
};

