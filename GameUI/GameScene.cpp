#include "GameScene.h"

GameScene::GameScene(QWidget* parent) :
	QWidget(parent),
	m_firstShow{ true },
	m_bestScore{ new QLCDNumber() },
	m_currentScore{ new QLCDNumber() },
	m_colorsFrame{ new ColorsFrame() },
	m_gameListener(std::shared_ptr<GameListener>(new GameListener())),
	m_resultLabel { new QLabel() }
{
}

void GameScene::showEvent(QShowEvent* event)
{
	if (m_firstShow)
	{
		m_bestScore = findChild<QLCDNumber*>("bestScore");
		m_currentScore = findChild<QLCDNumber*>("currentScore");
		m_resultLabel = findChild<QLabel*>("resultLabel");
		m_colorsFrame = findChild<ColorsFrame*>("colorsFrame");
		m_historyFrame = findChild<HistoryFrame*>("historyFrame");
		m_backToMainMenuButton = findChild<QPushButton*>("mainMenuButton");
		m_confirmSequenceButton = findChild<QPushButton*>("confirmButton");

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
	m_resultLabel->clear();
	m_confirmSequenceButton->setEnabled(true);
}

void GameScene::SetupConnections()
{
	QObject::connect(m_backToMainMenuButton, &QPushButton::released, this, [this]()
		{
			m_game->StopGame();
			m_currentScore->display(0);
			emit BackToMainMenuButtonPressed();
		});
	QObject::connect(m_gameListener.get(), &GameListener::ColorReceived, m_colorsFrame, &ColorsFrame::OnColorReceived);
	QObject::connect(m_gameListener.get(), &GameListener::SequenceEnded, m_colorsFrame, &ColorsFrame::OnSequenceEnded);
	QObject::connect(m_gameListener.get(), &GameListener::ScoreChanged, this, &GameScene::OnScoreUpdated);
	QObject::connect(m_gameListener.get(), &GameListener::RoundEnded, m_historyFrame, &HistoryFrame::OnRoundEnded);
	QObject::connect(m_gameListener.get(), &GameListener::GameEnded, this, &GameScene::OnGameEnded);
	QObject::connect(m_colorsFrame, &ColorsFrame::ColorSelected, this, [this](EColor selectedColor) 
		{
			m_game->SelectColor(selectedColor);
			m_historyFrame->UpdateSelectedColors(m_game->GetCurrentSequence());
		});
	QObject::connect(m_confirmSequenceButton, &QPushButton::released, this, [this]() {
			m_game->CheckSequence();
		});
}

void GameScene::OnScoreUpdated(int score)
{
	m_currentScore->display(score);
}

void GameScene::OnRoundEnded()
{
}

void GameScene::OnGameEnded()
{
	m_resultLabel->setText("Final Score: " + QString::number(m_currentScore->intValue()));
	m_confirmSequenceButton->setEnabled(false);
	m_historyFrame->OnRoundEnded();
}