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
	emit ScoreChanged(score);
}

void GameListener::OnRoundEnded()
{
	emit RoundEnded();
}

void GameListener::OnGameEnded()
{
	emit GameEnded();
}
