#pragma once
#include "IStrategy.h"

class HardStrategy : public IStrategy
{
public:
	/**
	 * Fetches the next sequence of colors
	 *
	 * \return Vector of colors
	 */
	ColorSequence NextSequence() override;
	/**
	 * Gets the delay between each color blinking
	 *
	 * \return
	 */
	Milliseconds GetDelay() override;

	/**
	 * Resets the strategy
	 *
	 */
	void Reset() override;

private:
	int m_round = 0;
};

