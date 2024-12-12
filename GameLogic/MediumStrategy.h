#pragma once
#include "IStrategy.h"

class MediumStrategy : public IStrategy
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
	ColorSequence m_sequence;
};

