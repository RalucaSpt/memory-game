#pragma once
#include "IStrategy.h"

class HardStrategy : public IStrategy
{
public:
	ColorSequence NextSequence() override;
	Milliseconds GetDelay() override;

private:
	int m_round = 0;
};

