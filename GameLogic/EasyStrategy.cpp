#include "EasyStrategy.h"

ColorSequence EasyStrategy::NextSequence()
{
	m_sequence.push_back(static_cast<EColor>(GetRandomNumber(0, 1)));

	return m_sequence;
}

Milliseconds EasyStrategy::GetDelay()
{
	return Milliseconds(1000);
}

void EasyStrategy::Reset()
{
	m_sequence.clear();
}
