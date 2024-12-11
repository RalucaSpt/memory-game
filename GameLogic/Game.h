#pragma once
#include <vector>
#include <functional>

#include "IGame.h"
#include "EColor.h"
#include "ICommand.h"
#include "EGameState.h"

using GamePtr = std::shared_ptr<class Game>;

using NotifyFunction = std::function<void(IGameListener*)>;

class Game : public IGame
{
public:
	Game();

	void SetStrategy(StrategyPtr strategy) override;

	void StartGame() override;
	void StopGame() override;

	void SelectColor(EColor color) override;
	void Undo() override;
	void CheckSequence() override;

	ColorSequence GetCurrentSequence() override;

	void Subscribe(GameListenerWeakPtr listener) override;
	void Unsubscribe(GameListenerWeakPtr listener) override;

	void AddColor(EColor color);
	void RemoveColor();

private:
	void CreateSequence();
	void NextTurn();
	void EndGame();
	void ResetGame();

	bool VerifyPlayerSequence();

	void NotifyListeners(NotifyFunction function);

	NotifyFunction GetNotifyColorReceived(EColor color);
	NotifyFunction GetNotifySequenceEnd();
	NotifyFunction GetNotifyScoreChanged(int index);
	NotifyFunction GetNotifyRoundEnded();
	NotifyFunction GetNotifyGameEnded();

private:
	EGameState m_state;

	ColorSequence m_colorSequence;
	ColorSequence m_playerSequence;
	CommandSequence m_playerActions;

	StrategyPtr m_strategy;

	Listeners m_listeners;

	int m_score;

	bool m_stopping;
};
