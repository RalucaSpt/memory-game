#include "Observable.h"
#include <algorithm>

void Observable::AddListener(IGameListener* listener)
{
    m_listeners.push_back(listener);
}

void Observable::RemoveListener(IGameListener* listener)
{
    m_listeners.erase(
        std::remove(m_listeners.begin(), m_listeners.end(), listener),
        m_listeners.end()
    );
}

void Observable::NotifyOnPressStart()
{
    for (IGameListener* listener : m_listeners)
    {
        listener->OnPressStart(); 
    }
}

void Observable::NotifyOnMoveMade()
{
    for (IGameListener* listener : m_listeners)
    {
        listener->OnMoveMade();
    }
}
