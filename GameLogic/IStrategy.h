#pragma once
#include "IGame.h"

#include <random>
#include <chrono>

using StrategyPtr = std::shared_ptr<class IStrategy>;

using Milliseconds = std::chrono::milliseconds;

class IStrategy
{
public:
	/**
	 * abstract: Generates the next sequence
	 *
	 * \return The next sequence
	 */
	virtual ColorSequence NextSequence() = 0;
	/**
	 * abstract: Gets the delay between each color blinking
	 * 
	 * \return The delay in ms
	 */
	virtual Milliseconds GetDelay() = 0;
	/**
	 * abstract: Reset the strategy
	 * 
	 */
	virtual void Reset() = 0;

protected:
	/**
	 * Generates a random number
	 * 
	 * \param from Range start
	 * \param to Range end
	 * \return A random number between from and to
	 */
	int GetRandomNumber(int from, int to)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distrib(from, to);

		return distrib(gen);
	}
};