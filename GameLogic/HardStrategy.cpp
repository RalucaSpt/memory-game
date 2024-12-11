#include "HardStrategy.h"

ColorSequence HardStrategy::NextSequence()
{
	ColorSequence sequence;
	
	for(int i = 0; i <= m_round; ++i)
		sequence.push_back(static_cast<EColor>(GetRandomNumber(0, 7)));

	++m_round;

	return sequence;
}

Milliseconds HardStrategy::GetDelay()
{
	return Milliseconds(1600);
}

void HardStrategy::Reset()
{
	m_round = 0;
}
