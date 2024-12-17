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
	void OnGameEnded();

private:
	void SetupConnections();
	void ToggleButtons(bool enable);
	void ToggleEndOfDisplayingSequence(bool isFinished);

	void SaveBestScore();
	void LoadBestScore();

private:
	const QString kBestScoreFileName = "BestScore.json";
	bool m_firstShow;
	bool m_firstColorReceived;
	QLCDNumber* m_bestScore;
	QLCDNumber* m_currentScore;
	QPushButton* m_backToMainMenuButton;
	QPushButton* m_confirmSequenceButton;
	QPushButton* m_undoButton;
	QLabel* m_resultLabel;
	QLabel* m_statusLabel;
	QString m_statusLabelStyleSheet;
	ColorsFrame* m_colorsFrame;
	HistoryFrame* m_historyFrame;
	std::shared_ptr<GameListener> m_gameListener;
	IGamePtr m_game;
};
