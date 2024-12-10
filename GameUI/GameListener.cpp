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
	int a = 5;
}

void GameListener::OnRoundEnded()
{
	int a = 5;
}

void GameListener::OnGameEnded()
{
	int a = 5;
}
