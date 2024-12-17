#include "GameUI.h"
#include <QThread>
#include <QTimer>

GameUI::GameUI(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	SetupConnections();
	resize(800, 600);
}

void GameUI::SetupConnections()
{
	//Menu Scene
	QObject::connect(ui.menuScene, &MenuScene::StartButtonPressed, this, [this](EDifficulty difficulty)
		{
			ui.stackedWidget->setCurrentWidget(ui.gameScene);
			ui.gameScene->OnNewGameStarted(difficulty);
		});
	QObject::connect(ui.menuScene, &MenuScene::QuitButtonPressed, this, []() { QCoreApplication::quit(); });

	//Game Scene
	QObject::connect(ui.gameScene, &GameScene::BackToMainMenuButtonPressed, this, [this]()
		{
			ui.stackedWidget->setCurrentWidget(ui.menuScene);
		});
}