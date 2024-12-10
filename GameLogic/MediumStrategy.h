#pragma once
#include "IStrategy.h"

class MediumStrategy : public IStrategy
{
public:
	ColorSequence NextSequence() override;
	Milliseconds GetDelay() override;

	void Reset() override;

private:
	ColorSequence m_sequence;
};

