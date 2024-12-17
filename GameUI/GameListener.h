#pragma once

#include "IGameListener.h"
#include <QObject>

class GameListener : public QObject, public IGameListener
{
	Q_OBJECT

public:
	GameListener(QObject* parent = nullptr) : QObject(parent) {}

	// Override the interface methods
	void OnColorReceived(EColor color) override;
	void OnSequenceEnd() override;
	void OnScoreChanged(int score) override;
	void OnRoundEnded() override;
	void OnGameEnded() override;

	// Destructor
	virtual ~GameListener() = default;

signals:
	void ColorReceived(EColor color);
	void SequenceEnded();
	void ScoreChanged(int score);
	void RoundEnded();
	void GameEnded();
};
