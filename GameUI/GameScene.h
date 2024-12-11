#pragma once

#include <QtWidgets/QFrame>
#include <QPushButton>
#include <QLCDNumber>
#include <QLabel>
#include "ColorsFrame.h"
#include "IGame.h"
#include "GameListener.h"
#include "HistoryFrame.h"

class GameScene : public QWidget
{
	Q_OBJECT

public:
	GameScene(QWidget* parent = nullptr);
	~GameScene() override = default;

	void showEvent(QShowEvent* event) override;

signals:
	void BackToMainMenuButtonPressed();

public slots:
	void OnNewGameStarted(EDifficulty difficulty);

private slots:
	void OnScoreUpdated(int score);
	void OnRoundEnded();
	void OnGameEnded();

private:
	void SetupConnections();

private:
	bool m_firstShow;
	QLCDNumber* m_bestScore;
	QLCDNumber* m_currentScore;
	QPushButton* m_backToMainMenuButton;
	QPushButton* m_confirmSequenceButton;
	QLabel* m_resultLabel;
	ColorsFrame* m_colorsFrame;
	HistoryFrame* m_historyFrame;
	std::shared_ptr<GameListener> m_gameListener;
	IGamePtr m_game;
};
