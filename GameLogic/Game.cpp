#include "Game.h"
#include <random>

namespace gameLogic {

    Game::Game()
        : Observable(), m_playerCurrentMoveNumber{ 0 }, m_score{ 0 }, m_maxScore{ 0 }, m_isGameOver{ false } 
    {
        /* --EMPTY-- */
    }

    void Game::StartNewGame()
    {
        m_playerCurrentMoveNumber = 0;
        m_score = 0;
        m_moveSequence.clear();
        NotifyOnPressStart();
    }

    void Game::MakeMove(Color color)
    {
        if (VerifyPlayerMoveSequence(color))
        {
            if (m_playerCurrentMoveNumber == m_moveSequence.size())
            {
                AddLevel();
                if (CheckNewRecord())
                {
                    m_maxScore = m_score;
                }
                RandomColorGenerator();
                ResetPlayerMove();
                m_isSequenceOver = true;
            }

        }
        else
        {
            m_isGameOver = true;
        }
        NotifyOnMoveMade();
    }

    std::vector<Color> Game::RandomColorGenerator()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(1, 4);

        m_moveSequence.push_back(static_cast<Color>(distrib(gen)));
        return m_moveSequence;
    }

    bool Game::VerifyPlayerMoveSequence(Color playerMove)
    {
        if (m_playerCurrentMoveNumber < m_moveSequence.size() &&
            m_moveSequence[m_playerCurrentMoveNumber] == playerMove)
        {
            m_playerCurrentMoveNumber++;
            return true;
        }
        return false;
    }

    bool Game::CheckNewRecord()
    {
        if (m_score > m_maxScore)
        {
            return true;
        }
        return false;
    }

    const std::vector<Color>& Game::GetMoveSequence() const
    {
        return m_moveSequence;
    }

    int Game::GetMaxScore() const
    {
        return m_maxScore;
    }

    int Game::GetLevel() const
    {
        return m_score;
    }

    int Game::AddLevel()
    {
        return ++m_score;
    }

    int Game::GetPlayerMove() const
    {
        return m_playerCurrentMoveNumber;
    }

    bool Game::IsGameOver() const
    {
        return m_isGameOver;
    }

    bool Game::IsSequenceOver() const
    {
        return m_isSequenceOver;
    }

    void Game::SetIsSequenceOver(bool isSequenceOver)
    {
        m_isSequenceOver = isSequenceOver;
    }

    void Game::ResetPlayerMove()
    {
        m_playerCurrentMoveNumber = 0;
    }

    
} 
