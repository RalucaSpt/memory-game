#pragma once
#include <vector>
#include <memory>

#include "EColor.h"
#include "EDifficulty.h"
#include "IGameListener.h"

using IGamePtr = std::shared_ptr<class IGame>;

using ColorSequence = std::vector<EColor>;

using StrategyPtr = std::shared_ptr<class IStrategy>;

class IGame
{
public:
	static IGamePtr Produce(EDifficulty difficulty, StrategyPtr customStrategy = nullptr);

	virtual void SetStrategy(StrategyPtr strategy) = 0;

	virtual void StartGame() = 0;
	virtual void StopGame() = 0;

	virtual void SelectColor(EColor color) = 0;
	virtual void Undo() = 0;
	virtual void CheckSequence() = 0;

	virtual ColorSequence GetCurrentSequence() = 0;
	
	virtual void Subscribe(GameListenerWeakPtr listener) = 0;
	virtual void Unsubscribe(GameListenerWeakPtr listener) = 0;
};