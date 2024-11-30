#include "GameUI.h"

GameUI::GameUI(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
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

