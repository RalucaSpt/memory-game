#include "pch.h"
#include "Game.h"

namespace SimonSaysTests
{
	class MockGame : public IGame
	{
	public:
		MOCK_METHOD(void, StartGame, (), (override));
		MOCK_METHOD(void, StopGame, (), (override));
		MOCK_METHOD(void, SelectColor, (EColor color), (override));
		MOCK_METHOD(void, Undo, (), (override));
		MOCK_METHOD(void, CheckSequence, (), (override));
		MOCK_METHOD(void, SetStrategy, (StrategyPtr strategy), (override));
		MOCK_METHOD(ColorSequence, GetCurrentSequence, (), (override));
		MOCK_METHOD(void, Subscribe, (GameListenerWeakPtr listener), (override));
		MOCK_METHOD(void, Unsubscribe, (GameListenerWeakPtr listener), (override));
	};


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

	TEST(GameTests, MockStopGame)
	{
		MockGame mockGame;
		EXPECT_CALL(mockGame, StopGame()).Times(1);

		mockGame.StopGame();
	}

	TEST(GameTests, MockSelectColor)
	{
		MockGame mockGame;
		EXPECT_CALL(mockGame, SelectColor(EColor::Red)).Times(1);

		mockGame.SelectColor(EColor::Red);
	}

	TEST(GameTests, MockGetCurrentSequence)
	{
		MockGame mockGame;
		ColorSequence expectedSequence = { EColor::Red, EColor::Green };
		EXPECT_CALL(mockGame, GetCurrentSequence()).WillOnce(testing::Return(expectedSequence));

		ColorSequence sequence = mockGame.GetCurrentSequence();
		EXPECT_EQ(sequence, expectedSequence);
	}

}
