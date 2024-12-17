#include "pch.h"
#include "EasyStrategy.h"
#include "MediumStrategy.h"
#include "HardStrategy.h"

namespace SimonSaysTests
{

	TEST(StrategyTests, EasyStrategy)
	{
		EasyStrategy strategy;
		ColorSequence sequence = strategy.NextSequence();
		ASSERT_EQ(sequence.size(), 1);
	}

	TEST(StrategyTests, MediumStrategy)
	{
		MediumStrategy strategy;
		ColorSequence sequence = strategy.NextSequence();
		ASSERT_EQ(sequence.size(), 1);
	}

	TEST(StrategyTests, HardStrategy)
	{
		HardStrategy strategy;
		ColorSequence sequence = strategy.NextSequence();
		ASSERT_EQ(sequence.size(), 1);
	}

	TEST(StrategyTests, HardStrategyRound)
	{
		HardStrategy strategy;
		ColorSequence sequence = strategy.NextSequence();
		ASSERT_EQ(sequence.size(), 1);
		sequence = strategy.NextSequence();
		ASSERT_EQ(sequence.size(), 2);
	}

	TEST(StrategyTests, HardStrategyReset)
	{
		HardStrategy strategy;
		ColorSequence sequence = strategy.NextSequence();
		ASSERT_EQ(sequence.size(), 1);
		sequence = strategy.NextSequence();
		ASSERT_EQ(sequence.size(), 2);
		strategy.Reset();
		sequence = strategy.NextSequence();
		ASSERT_EQ(sequence.size(), 1);
	}

	TEST(StrategyTests, MediumStrategyReset)
	{
		MediumStrategy strategy;
		ColorSequence sequence = strategy.NextSequence();
		ASSERT_EQ(sequence.size(), 1);
		sequence = strategy.NextSequence();
		ASSERT_EQ(sequence.size(), 2);
		strategy.Reset();
		sequence = strategy.NextSequence();
		ASSERT_EQ(sequence.size(), 1);
	}

	TEST(StrategyTests, EasyStrategyReset)
	{
		EasyStrategy strategy;
		ColorSequence sequence = strategy.NextSequence();
		ASSERT_EQ(sequence.size(), 1);
		sequence = strategy.NextSequence();
		ASSERT_EQ(sequence.size(), 2);
		strategy.Reset();
		sequence = strategy.NextSequence();
		ASSERT_EQ(sequence.size(), 1);
	}

	TEST(StrategyTests, EasyStrategyDelay)
	{
		EasyStrategy strategy;
		Milliseconds delay = strategy.GetDelay();
		ASSERT_EQ(delay.count(), 2000);
	}

	TEST(StrategyTests, MediumStrategyDelay)
	{
		MediumStrategy strategy;
		Milliseconds delay = strategy.GetDelay();
		ASSERT_EQ(delay.count(), 1400);
	}

	TEST(StrategyTests, HardStrategyDelay)
	{
		HardStrategy strategy;
		Milliseconds delay = strategy.GetDelay();
		ASSERT_EQ(delay.count(), 1600);
	}

}

