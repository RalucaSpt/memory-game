#include "Game.h"

void Game::StartGame()
{
	NotifyAll(UserChoice::STARTGAME);
}

void Game::MakeMove()
{
	NotifyAll(UserChoice::MAKEMOVE);
}

std::vector<unsigned char> Game::GetMoveSequence()
{
	std::random_device rd;                          // Seed
	std::mt19937 gen(rd());                         // Random number generator
	std::uniform_int_distribution<> distrib(1, 8);  // Distribution range [1, 8]

	m_moveSequence.push_back(distrib(gen));
	return m_moveSequence;
}

bool Game::VerifyPlayerMoveSequence(std::vector<unsigned char> playerSequence)
{
	if (m_moveSequence == playerSequence)
	{
		return true;
	}
	return false;
}
