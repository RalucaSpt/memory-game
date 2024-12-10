#include "GameUI.h"
#include <QThread>
#include <QTimer>

GameUI::GameUI(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	SetupConnections();
	resize(800, 600);
	//m_game->AddListener(this);

	/*for (auto& button : { ui.redButton, ui.blueButton, ui.greenButton, ui.yellowButton })
	{
		connect(button, &QPushButton::clicked, this, &GameUI::HandleButtonPress);
	}*/
}

void GameUI::SetupConnections()
{
	//Menu Scene
	QObject::connect(ui.menuScene, &MenuScene::StartButtonPressed, this, [this](EDifficulty difficulty)
		{
			/*m_game = IGame::Produce(difficulty);
			m_game->Subscribe(m_gameListener);
			m_game->StartGame();*/
			ui.stackedWidget->setCurrentWidget(ui.gameScene);
			ui.gameScene->OnNewGameStarted(difficulty);
		});
	QObject::connect(ui.menuScene, &MenuScene::QuitButtonPressed, this, []() { QCoreApplication::quit(); });

	//Game Scene
	QObject::connect(ui.gameScene, &GameScene::BackToMainMenuButtonPressed, this, [this]()
		{
			ui.stackedWidget->setCurrentWidget(ui.menuScene);
		});

	//Game Listener
	//QObject::connect(m_gameListener.get(), &GameListener::ColorReceived, ui.colorsFrame, &ColorsFrame::OnColorReceived);
	/*QObject::connect(m_gameListener, &GameListener::sequenceEnded, m_gameScene, &GameScene::onSequenceEnded);
	QObject::connect(m_gameListener, &GameListener::scoreChanged, m_gameScene, &GameScene::onScoreUpdated);
	QObject::connect(m_gameListener, &GameListener::roundEnded, m_gameScene, &GameScene::onRoundEnded);
	QObject::connect(m_gameListener, &GameListener::gameEnded, m_gameScene, &GameScene::onGameEnded);*/
}

//QPushButton* GameUI::GetButtonForColor(Color color) const
//{
//	switch (color)
//	{
//	case RED: return ui.redButton;
//	case BLUE: return ui.blueButton;
//	case GREEN: return ui.greenButton;
//	case YELLOW: return ui.yellowButton;
//	default: return nullptr;
//	}
//}
//
//Color GameUI::GetColorForButton(QPushButton* button) const
//{
//	if (button == ui.redButton) return RED;
//	if (button == ui.blueButton) return BLUE;
//	if (button == ui.greenButton) return GREEN;
//	if (button == ui.yellowButton) return YELLOW;
//	return none;
//}
//
//void GameUI::SetButtonsEnabled(bool enabled)
//{
//	ui.redButton->setEnabled(enabled);
//	ui.blueButton->setEnabled(enabled);
//	ui.greenButton->setEnabled(enabled);
//	ui.yellowButton->setEnabled(enabled);
//}
//
//void GameUI::ShowSequence()
//{
//	const auto& sequence = m_game->GetMoveSequence();
//	m_game->SetIsSequenceOver(false);
//	int delay = m_difficultyDilay;
//	SetButtonsEnabled(false);
//
//	for (auto color : sequence)
//	{
//		QTimer::singleShot(delay, [this, color]()
//		{
//			HighlightButton(color);
//		});
//		delay += m_difficultyDilay + 100;
//	}
//
//	QTimer::singleShot(delay, [this]()
//	{
//		SetButtonsEnabled(true);
//	});
//}
//
//void GameUI::HighlightButton(Color color)
//{
//	QPushButton* button = GetButtonForColor(color);
//
//	if (button)
//	{
//		const QString originalStyle = button->styleSheet();
//		button->setStyleSheet("background-color: white;");
//		QTimer::singleShot(m_difficultyDilay, [button,originalStyle]()
//		{
//			button->setStyleSheet(originalStyle);
//		});
//	}
//}
//
//void GameUI::OnStartButtonClicked()
//{
//	switch (ui.difficultyComboBox->currentIndex())
//	{
//	case 0:
//		m_difficultyDilay = 1000;
//		break;
//	case 1:
//		m_difficultyDilay = 500;
//		break;
//	case 2:
//		m_difficultyDilay = 250;
//		break;
//	default:
//		m_difficultyDilay = 1000;
//		break;
//	}
//	ui.stackedWidget->setCurrentIndex(1);
//	startGame();
//}
//
//void GameUI::on_resetButton_clicked()
//{
//	ui.stackedWidget->setCurrentIndex(0);
//}
//
//void GameUI::startGame()
//{
//	m_game->StartNewGame();
//}
//
//void GameUI::HandleButtonPress()
//{
//	auto button = qobject_cast<QPushButton*>(sender());
//	if (!button) return;
//	Color color = GetColorForButton(button);
//
//	m_game->MakeMove(color);
//}
