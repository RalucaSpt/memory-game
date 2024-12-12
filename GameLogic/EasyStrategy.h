#pragma once
#include "IStrategy.h"

class EasyStrategy : public IStrategy
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
	 * \return The delay in ms
	 */
	Milliseconds GetDelay() override;

	/**
	 * Resets the strategy
	 *
	 */
	void Reset() override;

private:
	ColorSequence m_sequence;
};

