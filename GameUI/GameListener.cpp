#include "GameListener.h"

void GameListener::OnColorReceived(EColor color)
{
	emit ColorReceived(color);
}

void GameListener::OnSequenceEnd()
{
	emit SequenceEnded();
}

void GameListener::OnScoreChanged(int score)
{
	std::cout << "Score changed to: " << score << std::endl;
}

void GameListener::OnRoundEnded()
{
	std::cout << "Round has ended." << std::endl;
}

void GameListener::OnGameEnded()
{
	std::cout << "Game has ended." << std::endl;
}
