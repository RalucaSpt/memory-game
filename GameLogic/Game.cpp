#include "Game.h"

#include <random>
#include <thread>

#include "SelectColorCommand.h"
#include "EasyStrategy.h"
#include "MediumStrategy.h"
#include "HardStrategy.h"

Game::Game()
	: m_state{ EGameState::ReceivingSequence }
	, m_colorSequence{}
	, m_playerSequence{}
	, m_playerActions{}
	, m_strategy{}
	, m_score{ 0 }
{
	/* --EMPTY-- */
}

IGamePtr IGame::Produce(EDifficulty difficulty, StrategyPtr customStrategy)
{
	IGamePtr game = std::make_shared<Game>();

	switch (difficulty)
	{
	case EDifficulty::Easy:
		game->SetStrategy(std::make_shared<EasyStrategy>());
		break;
	case EDifficulty::Medium:
		game->SetStrategy(std::make_shared<MediumStrategy>());
		break;
	case EDifficulty::Hard:
		game->SetStrategy(std::make_shared<HardStrategy>());
		break;
	case EDifficulty::Custom:
		game->SetStrategy(customStrategy);
		break;
	}

	return game;
}

void Game::SetStrategy(StrategyPtr strategy)
{
	m_strategy = strategy;
}

void Game::StartGame()
{
	if (m_state != EGameState::End)
		return;

	ResetGame();
}

void Game::SelectColor(EColor color)
{
	if (m_state != EGameState::Playing)
		return;

	auto command = std::make_shared<SelectColorCommand>(shared_from_this(), color);
	m_playerActions.push_back(command);
	m_playerActions.back()->Execute();
}

void Game::Undo()
{
	if (!m_playerActions.empty())
	{
		m_playerActions.back()->Undo();
		m_playerActions.pop_back();
	}
}

void Game::CheckSequence()
{
	if (m_state != EGameState::Playing)
		return;

	if (VerifyPlayerSequence())
		NextTurn();
	else
		EndGame();
}

ColorSequence Game::GetCurrentSequence()
{
	return m_playerSequence;
}

void Game::Subscribe(GameListenerWeakPtr listener)
{
	m_listeners.push_back(listener);
}

void Game::Unsubscribe(GameListenerWeakPtr listener)
{
	auto listenerPtr = listener.lock();
	if (!listenerPtr)
		return;

	auto it = std::ranges::remove_if(m_listeners,
		[&listenerPtr](const GameListenerWeakPtr& listener)
		{
			auto elemPtr = listener.lock();
			return elemPtr && elemPtr == listenerPtr;
		});

	m_listeners.erase(it.begin(), it.end());
}

void Game::AddColor(EColor color)
{
	m_playerSequence.emplace_back(color);
}

void Game::RemoveColor()
{
	m_playerSequence.pop_back();
}

void Game::NextTurn()
{
	m_playerSequence.clear();
	m_playerActions.clear();

	NotifyListeners(GetNotifyRoundEnded());
	NotifyListeners(GetNotifyScoreChanged(++m_score));

	m_state = EGameState::ReceivingSequence;

	std::thread([this]() { CreateSequence(); }).detach();
}

void Game::EndGame()
{
	m_state = EGameState::End;

	NotifyListeners(GetNotifyGameEnded());
}

void Game::ResetGame()
{
	m_state = EGameState::ReceivingSequence;

	m_strategy->Reset();
	
	m_colorSequence.clear();
	m_playerSequence.clear();
	m_playerActions.clear();

	m_score = 0;

	std::thread([this]() { CreateSequence(); }).detach();
}

void Game::CreateSequence()
{
	m_colorSequence = m_strategy->NextSequence();

	for (EColor color : m_colorSequence)
	{
		NotifyListeners(GetNotifyColorReceived(color));
		std::this_thread::sleep_for(m_strategy->GetDelay());
	}

	NotifyListeners(GetNotifySequenceEnd());

	m_state = EGameState::Playing;
}

bool Game::VerifyPlayerSequence()
{
	return m_colorSequence == m_playerSequence;
}

void Game::NotifyListeners(NotifyFunction function)
{
	for (auto listener : m_listeners)
	{
		if (auto sp = listener.lock())
		{
			function(sp.get());
		}
	}
}

NotifyFunction Game::GetNotifyColorReceived(EColor color)
{
	return [&](IGameListener* listener)
		{
			listener->OnColorReceived(color);
		};
}

NotifyFunction Game::GetNotifySequenceEnd()
{
	return [&](IGameListener* listener)
		{
			listener->OnSequenceEnd();
		};
}

NotifyFunction Game::GetNotifyScoreChanged(int index)
{
	return [&](IGameListener* listener)
		{
			listener->OnScoreChanged(index);
		};
}

NotifyFunction Game::GetNotifyRoundEnded()
{
	return [&](IGameListener* listener)
		{
			listener->OnRoundEnded();
		};
}

NotifyFunction Game::GetNotifyGameEnded()
{
	return [&](IGameListener* listener)
		{
			listener->OnGameEnded();
		};
}
