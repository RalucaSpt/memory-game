#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Game.h"
#include "MockGameListener.h"

using namespace gameLogic;

TEST(GameTest, StartNewGame_ResetsStateCorrectly) {
    Game game;

    game.AddLevel();  
    game.RandomColorGenerator();  
    game.ResetPlayerMove();

    ASSERT_GT(game.GetMoveSequence().size(), 0);

    game.StartNewGame();

    EXPECT_EQ(game.GetMoveSequence().size(), 0);
    EXPECT_EQ(game.GetPlayerMove(), 0);
    EXPECT_EQ(game.GetMaxScore(), 0);
}

TEST(GameTest, RandomColorGenerator_AddsColorToSequence) {
    Game game;

    auto initialSize = game.GetMoveSequence().size();
    game.RandomColorGenerator();

    EXPECT_EQ(game.GetMoveSequence().size(), initialSize + 1);
}

TEST(GameTest, VerifyPlayerMoveSequence_ValidatesCorrectly) {
    Game game;

    game.RandomColorGenerator();
    Color correctMove = game.GetMoveSequence().front();

    EXPECT_TRUE(game.VerifyPlayerMoveSequence(correctMove));

    EXPECT_FALSE(game.VerifyPlayerMoveSequence(static_cast<Color>((correctMove + 1) % 4)));
}

TEST(GameTest, CheckNewRecord_DetectsCorrectly) {
    Game game;

    game.AddLevel();

    game.AddLevel();

    EXPECT_TRUE(game.CheckNewRecord());

    EXPECT_FALSE(game.CheckNewRecord());
}

TEST(GameTest, AddLevel_IncrementsScore) {
    Game game;

    int initialScore = game.GetMaxScore();
    game.AddLevel();
    game.CheckNewRecord();  

    EXPECT_EQ(game.GetMaxScore(), initialScore + 1);
}


TEST(GameTest, ResetPlayerMove_ResetsCorrectly) {
    Game game;

    game.RandomColorGenerator();
    game.VerifyPlayerMoveSequence(game.GetMoveSequence().front());

    ASSERT_GT(game.GetPlayerMove(), 0);

    game.ResetPlayerMove();

    EXPECT_EQ(game.GetPlayerMove(), 0);
}

