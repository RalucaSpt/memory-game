#include "Game.h"

namespace gameLogic
{
	Game::Game() :
		Observable()
	{
		m_playerMoveNumber = DEFAULT_SEQUENCE_LENGHT;
	}

	void Game::StartGame()
	{
		m_playerMoveNumber = 0;
		NotifyAll(UserChoice::STARTGAME);
	}

	void Game::MakeMove()
	{
		NotifyAll(UserChoice::MAKEMOVE);
	}

	std::vector<unsigned char> Game::GetMoveSequence()
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distrib(1, 8);

		m_moveSequence.push_back(distrib(gen));
		return m_moveSequence;
	}

	bool Game::VerifyPlayerMoveSequence(unsigned char playerMove)
	{
		if (m_moveSequence[m_playerMoveNumber] == playerMove)
		{
			return true;
		}
		return false;
	}


}