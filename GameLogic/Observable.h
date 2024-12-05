#pragma once
#include <vector>
#include "IGameListener.h"
using namespace gameLogic;

enum UserChoice : signed char
{
	NONE = 0,
	STARTGAME = 1,
	MAKEMOVE = 2,
	COLOR_GENERATED = 3
};

class Observable
{
public:
	Observable() = default;

	void AddListener(IGameListener* listener);
	void RemoveListener(IGameListener* listener);
	void NotifyOnPressStart();
	void NotifyOnMoveMade();

private:
	std::vector<IGameListener*> m_listeners;
};
