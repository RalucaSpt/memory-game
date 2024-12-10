#pragma once

#include <QtWidgets/QFrame>
#include <QPushButton>
#include <QLCDNumber>
#include "ColorsFrame.h"
#include "IGame.h"
#include "GameListener.h"

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
	void OnSequenceEnded();
	void OnScoreUpdated(int score);
	void OnRoundEnded();
	void OnGameEnded();

private:
	void SetupConnections();

private:
	bool m_firstShow;
	QLCDNumber* m_bestScore;
	QLCDNumber* m_currentScore;
	QPushButton* m_backToMainMenu;
	ColorsFrame* m_colorsFrame;
	std::shared_ptr<GameListener> m_gameListener;
	IGamePtr m_game;
};
