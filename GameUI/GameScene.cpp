#include "GameScene.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

GameScene::GameScene(QWidget* parent) :
	QWidget(parent),
	m_firstShow{ true },
	m_firstColorReceived { false },
	m_bestScore{ new QLCDNumber() },
	m_currentScore{ new QLCDNumber() },
	m_colorsFrame{ new ColorsFrame() },
	m_gameListener(std::shared_ptr<GameListener>(new GameListener())),
	m_resultLabel { new QLabel() },
	m_undoButton{ new QPushButton() },
	m_backToMainMenuButton { new QPushButton() },
	m_confirmSequenceButton{ new QPushButton() },
	m_historyFrame { new HistoryFrame() }
{
	m_statusLabelStyleSheet = QString(
		"background-color: %1;"
		"border-radius: 35px;");
}

void GameScene::showEvent(QShowEvent* event)
{
	if (m_firstShow)
	{
		m_bestScore = findChild<QLCDNumber*>("bestScore");
		m_currentScore = findChild<QLCDNumber*>("currentScore");
		m_resultLabel = findChild<QLabel*>("resultLabel");
		m_statusLabel = findChild<QLabel*>("statusLabel");
		m_colorsFrame = findChild<ColorsFrame*>("colorsFrame");
		m_historyFrame = findChild<HistoryFrame*>("historyFrame");
		m_backToMainMenuButton = findChild<QPushButton*>("mainMenuButton");
		m_confirmSequenceButton = findChild<QPushButton*>("confirmButton");
		m_undoButton = findChild<QPushButton*>("undoButton");

		SetupConnections();

		m_firstShow = false;
	}
}

void GameScene::OnNewGameStarted(EDifficulty difficulty)
{
	m_game = IGame::Produce(difficulty);
	m_game->Subscribe(m_gameListener);
	m_game->StartGame();
	LoadBestScore();
	m_colorsFrame->AddButtonsAccordingToDifficulty(difficulty);
	m_resultLabel->clear();
	ToggleButtons(true);
	ToggleEndOfDisplayingSequence(false);
}

void GameScene::SetupConnections()
{
	QObject::connect(m_gameListener.get(), &GameListener::ColorReceived, this, [this](EColor colorReceived) {
			if (!m_firstColorReceived) {
				ToggleEndOfDisplayingSequence(false);
				m_firstColorReceived = true;
			}
			QMetaObject::invokeMethod(m_colorsFrame, "OnColorReceived", Qt::QueuedConnection, Q_ARG(EColor, colorReceived));
		});
	QObject::connect(m_gameListener.get(), &GameListener::SequenceEnded, this, [this]() {
			m_firstColorReceived = false;
			ToggleEndOfDisplayingSequence(true);
			QMetaObject::invokeMethod(m_colorsFrame, "OnSequenceEnded", Qt::QueuedConnection);
		});
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
	QObject::connect(m_undoButton, &QPushButton::released, this, [this]() {
		m_game->Undo();
		QMetaObject::invokeMethod(m_historyFrame, "OnUndo", Qt::QueuedConnection);
	});
	QObject::connect(m_backToMainMenuButton, &QPushButton::released, this, [this]()
		{
			m_game->StopGame();
			m_currentScore->display(0);
			SaveBestScore();
			emit BackToMainMenuButtonPressed();
		});
}

void GameScene::ToggleButtons(bool enable)
{
	m_confirmSequenceButton->setEnabled(enable);
	m_colorsFrame->setEnabled(enable);
	m_undoButton->setEnabled(enable);
	ToggleEndOfDisplayingSequence(enable);
}

void GameScene::ToggleEndOfDisplayingSequence(bool isFinished)
{
	QString color = isFinished ? "green" : "red";
	m_statusLabel->setStyleSheet(m_statusLabelStyleSheet.arg(color));
	update();
}

void GameScene::SaveBestScore() {
	QFile file(kBestScoreFileName);
	if (!file.open(QIODevice::WriteOnly)) {
		qWarning("Could not open best score file for writing.");
		return;
	}

	QJsonObject json;
	json["bestScore"] = m_bestScore->intValue();

	QJsonDocument doc(json);
	file.write(doc.toJson());
	file.close();
}

void GameScene::LoadBestScore()
{
	QFile file(kBestScoreFileName);
	if (!file.open(QIODevice::ReadOnly)) {
		qWarning("Best score file not found, starting with default best score.");
		m_bestScore->display(0);
		return;
	}

	QByteArray data = file.readAll();
	QJsonDocument doc = QJsonDocument::fromJson(data);

	if (doc.isObject()) {
		QJsonObject json = doc.object();
		if (json.contains("bestScore") && json["bestScore"].isDouble()) {
			int bestScore = json["bestScore"].toInt();
			m_bestScore->display(bestScore);
		}
	}

	file.close();
}

void GameScene::OnScoreUpdated(int score)
{
	m_currentScore->display(score);
	if (m_currentScore->intValue() > m_bestScore->intValue()) {
		m_bestScore->display(m_currentScore->intValue());
	}
}

void GameScene::OnGameEnded()
{
	m_resultLabel->setText("Final Score: " + QString::number(m_currentScore->intValue()));
	ToggleButtons(false);
	QMetaObject::invokeMethod(m_historyFrame, "OnRoundEnded", Qt::QueuedConnection);
}