#pragma once
#include "pch.h"
#include "Observable.h"

class MockGameListener : public IGameListener
{
public:
	MOCK_METHOD(void, OnPressStart, (), (override)
	);
	MOCK_METHOD(void, OnMoveMade, (), (override)
	);
};
