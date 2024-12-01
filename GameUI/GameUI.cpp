#include "GameUI.h"

GameUI::GameUI(gameLogic::Game* game, QWidget* parent)
	: m_game(game), QMainWindow(parent)
{
	ui.setupUi(this);
	m_game->AddListener(this);

	m_redButton = ui.redButton;
	m_yellowButton = ui.yellowButton;
	m_blueButton = ui.greenButton;
	m_greenButton = ui.blueButton;
	m_scoreboard = new Scoreboard(0, 0, this);

	connect(m_blueButton, &QPushButton::clicked, this, []() {
		qDebug() << "Blue button clicked!";
		});

	connect(m_greenButton, &QPushButton::clicked, this, []() {
		qDebug() << "Green button clicked!";
		});

	connect(m_redButton, &QPushButton::clicked, this, []() {
		qDebug() << "Red button clicked!";
		});

	connect(m_yellowButton, &QPushButton::clicked, this, []() {
		qDebug() << "Yellow button clicked!";
		});
}

GameUI::~GameUI()
{
	delete m_scoreboard;
	delete m_redButton;
	delete m_blueButton;
	delete m_yellowButton;
	delete m_greenButton;
	m_game->RemoveListener(this); 
}

void GameUI::OnPressStart()
{
}

void GameUI::OnMoveMade()
{
}


void GameUI::startGame()
{
	qDebug() << "Game started!";
}

void GameUI::endGame()
{
	qDebug() << "Game ended!";
}

void GameUI::showSequence()
{
	qDebug() << "Showing sequence!";
}


void GameUI::checkSequence()
{
	qDebug() << "Checking sequence!";
}

void GameUI::updateScore()
{
	qDebug() << "Updating score!";
}

void GameUI::updateHighScore()
{
	qDebug() << "Updating highscore!";
}

void GameUI::resetScore()
{
	qDebug() << "Resetting score!";
}

void GameUI::resetHighScore()
{
	qDebug() << "Resetting highscore!";
}

void GameUI::OnColorGenerated(gameLogic::Color color)
{
	switch (color)
	{
	case gameLogic::Color::RED:
		ui.redButton->setStyleSheet("background-color: red;");
		break;
	case gameLogic::Color::BLUE:
		ui.blueButton->setStyleSheet("background-color: blue;");
		break;
	case gameLogic::Color::GREEN:
		ui.greenButton->setStyleSheet("background-color: green;");
		break;
	case gameLogic::Color::YELLOW:
		ui.yellowButton->setStyleSheet("background-color: yellow;");
		break;
	default:
		qDebug() << "No color generated.";
		break;
	}
}


