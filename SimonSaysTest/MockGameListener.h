#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Observable.h"

class MockGameListener : public IGameListener {
public:
    MOCK_METHOD(void, OnPressStart, (), (override));
    MOCK_METHOD(void, OnMoveMade, (), (override));
};
