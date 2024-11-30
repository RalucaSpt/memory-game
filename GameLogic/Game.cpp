#include "Game.h"

namespace gameLogic
{
	Game::Game() :
		Observable(), m_playerCurrentMoveNumber{ 0 }, m_level {0},m_maxScore{0}
	{
	}

	void Game::StartNewGame()
	{
		m_playerCurrentMoveNumber = 0;
		m_level = 1;
		NotifyAll(UserChoice::STARTGAME);
	}

	void Game::MakeMove()
	{
		NotifyAll(UserChoice::MAKEMOVE);
	}

	std::vector<Color> Game::RandomColorGenerator()
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distrib(1, 4);

		for (int i = 0; i < m_level; i++)
		{
			m_moveSequence.push_back((Color)distrib(gen));
		}
		return m_moveSequence;
	}

	bool Game::VerifyPlayerMoveSequence(Color playerMove)
	{
		if (m_moveSequence[m_playerCurrentMoveNumber] == playerMove)
		{
			m_playerCurrentMoveNumber+=1;
			return true;
		}
		return false;
	}

}