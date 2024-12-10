#pragma once
#include "IGame.h"

#include <random>
#include <chrono>

using StrategyPtr = std::shared_ptr<class IStrategy>;

using Milliseconds = std::chrono::milliseconds;

class IStrategy
{
public:
	virtual ColorSequence NextSequence() = 0;
	virtual Milliseconds GetDelay() = 0;

	virtual void Reset() = 0;

protected:
	int GetRandomNumber(int from, int to)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distrib(from, to);

		return distrib(gen);
	}
};