#include "GameScene.h"

GameScene::GameScene(QWidget* parent) :
	QWidget(parent),
	m_firstShow{ true },
	m_bestScore{ new QLCDNumber() },
	m_currentScore{ new QLCDNumber() },
	m_colorsFrame{ new ColorsFrame() },
	m_gameListener(std::shared_ptr<GameListener>(new GameListener()))
{
}

void GameScene::showEvent(QShowEvent* event)
{
	if (m_firstShow)
	{
		m_bestScore = findChild<QLCDNumber*>("bestScore");
		m_currentScore = findChild<QLCDNumber*>("currentScore");
		m_colorsFrame = findChild<ColorsFrame*>("colorsFrame");
		m_backToMainMenu = findChild<QPushButton*>("mainMenuButton");

		SetupConnections();

		m_firstShow = false;
	}
}

void GameScene::OnNewGameStarted(EDifficulty difficulty)
{
	m_game = IGame::Produce(difficulty);
	m_game->Subscribe(m_gameListener);
	m_game->StartGame();
	m_colorsFrame->AddButtonsAccordingToDifficulty(difficulty);
}

void GameScene::SetupConnections()
{
	QObject::connect(m_backToMainMenu, &QPushButton::released, this, [this]()
		{
			emit BackToMainMenuButtonPressed();
		});
	QObject::connect(m_gameListener.get(), &GameListener::ColorReceived, m_colorsFrame, &ColorsFrame::OnColorReceived);
	QObject::connect(m_gameListener.get(), &GameListener::SequenceEnded, this, &GameScene::OnSequenceEnded);
	QObject::connect(m_gameListener.get(), &GameListener::ScoreChanged, this, &GameScene::OnScoreUpdated);
	QObject::connect(m_gameListener.get(), &GameListener::RoundEnded, this, &GameScene::OnRoundEnded);
	QObject::connect(m_gameListener.get(), &GameListener::GameEnded, this, &GameScene::OnGameEnded);
}

void GameScene::OnSequenceEnded()
{
}

void GameScene::OnScoreUpdated(int score)
{
}

void GameScene::OnRoundEnded()
{
}

void GameScene::OnGameEnded()
{
}