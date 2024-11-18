#include "Observable.h"

void Observable::AddListener(IGameListener* listener)
{
	m_listeners.push_back(listener);
}

void Observable::RemoveListener(IGameListener* listener)
{
	auto func = [listener](IGameListener* el)
	{
		return el == listener;
	};
	m_listeners.erase(std::remove_if(m_listeners.begin(), m_listeners.end(), func));
}

void Observable::NotifyAll(UserChoice choice)
{
	switch (choice)
	{
	case NONE:
		break;
	case STARTGAME:
		for (auto it : m_listeners)
		{
			it->OnPressStart();
		}
		break;
	case MAKEMOVE:
		for (auto it : m_listeners)
		{
			it->OnMoveMade();
		}
		break;
	default:
		break;
	}


}
