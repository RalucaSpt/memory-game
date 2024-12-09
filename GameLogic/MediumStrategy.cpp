#include "MediumStrategy.h"

ColorSequence MediumStrategy::NextSequence()
{
	m_sequence.push_back(static_cast<EColor>(GetRandomNumber(0, 3)));

	return m_sequence;
}

Milliseconds MediumStrategy::GetDelay()
{
	return Milliseconds(700);
}
