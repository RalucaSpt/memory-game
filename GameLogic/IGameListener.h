#pragma once
#include <memory>

#include "EColor.h"

using GameListenerWeakPtr = std::weak_ptr<class IGameListener>;
using Listeners = std::vector<GameListenerWeakPtr>;

class IGameListener
{
public:
	virtual void OnColorReceived(EColor color) = 0;
	virtual void OnSequenceEnd() = 0;
	virtual void OnScoreChanged(int score) = 0;
	virtual void OnRoundEnded() = 0;
	virtual void OnGameEnded() = 0;
};
