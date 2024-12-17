#include "pch.h"
#include "Game.h"

namespace SimonSaysTests
{
	TEST(GameTests, StopGame)
	{
		Game game;
		game.StopGame();
	}

	TEST(GameTests, SelectColor)
	{
		Game game;
		game.SelectColor(EColor::Red);
	}

	TEST(GameTests, Undo)
	{
		Game game;
		game.Undo();
	}

	TEST(GameTests, CheckSequence)
	{
		Game game;
		game.CheckSequence();
	}

	TEST(GameTests, SetStrategy)
	{
		Game game;
		game.SetStrategy(nullptr);
	}

	TEST(GameTests, Produce)
	{
		IGamePtr game = IGame::Produce(EDifficulty::Easy);
	}

	TEST(GameTests, ProduceCustom)
	{
		IGamePtr game = IGame::Produce(EDifficulty::Custom, nullptr);
	}

	TEST(GameTests, ProduceMedium)
	{
		IGamePtr game = IGame::Produce(EDifficulty::Medium);
	}

	TEST(GameTests, ProduceHard)
	{
		IGamePtr game = IGame::Produce(EDifficulty::Hard);
	}

	TEST(GameTests, GetCurrentSequence)
	{
		Game game;
		ColorSequence sequence = game.GetCurrentSequence();

		EXPECT_EQ(sequence.size(), 0);
	}

	TEST(GameTests, GameDestructor)
	{
		Game* game = new Game();
		delete game;
	}

	TEST(GameTests, GameAddColor)
	{
		Game game;
		game.AddColor(EColor::Red);
	}

	TEST(GameTests, GameRemoveColor)
	{
		Game game;
		game.AddColor(EColor::Red);
		game.RemoveColor();
	}
}
