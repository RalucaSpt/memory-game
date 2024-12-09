#include "HardStrategy.h"

ColorSequence HardStrategy::NextSequence()
{
	ColorSequence sequence;
	
	for(int i = 0; i < m_round; ++i)
		sequence.push_back(static_cast<EColor>(GetRandomNumber(0, 3)));

	++m_round;

	return sequence;
}

Milliseconds HardStrategy::GetDelay()
{
	return Milliseconds(800);
}
