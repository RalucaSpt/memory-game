#include "SimonSaysUI.h"

void SimonSaysUI::setupConnections()
{
    buttons = new Buttons(ui.blueButton, ui.greenButton, ui.redButton, ui.yellowButton, this);

    connect(buttons->getRedButton(), &QPushButton::clicked, this, []() {
        qDebug() << "Red button clicked in SimonSaysUI!";
        });

	connect(buttons->getBlueButton(), &QPushButton::clicked, this, []() {
		qDebug() << "Blue button clicked in SimonSaysUI!";
		});

	connect(buttons->getYellowButton(), &QPushButton::clicked, this, []() {
		qDebug() << "Yellow button clicked in SimonSaysUI!";
		});

	connect(buttons->getGreenButton(), &QPushButton::clicked, this, []() {
		qDebug() << "Green button clicked in SimonSaysUI!";
		});

	scoreboard = new Scoreboard(ui.scoreLabel, ui.highScoreLabel, this);
}

SimonSaysUI::SimonSaysUI(QWidget* parent)
    : QMainWindow(parent), buttons(nullptr) {
    // Inițializează interfața grafică definită în .ui
    ui.setupUi(this);
	setupConnections();
    // Configurează fereastra
    setWindowTitle("Simon Says");
    resize(800, 800);
}

SimonSaysUI::~SimonSaysUI()
{
	delete buttons;
	delete scoreboard;
}

void SimonSaysUI::startGame()
{
	qDebug() << "Game started!";
}

void SimonSaysUI::endGame()
{
	qDebug() << "Game ended!";
}

void SimonSaysUI::showSequence()
{
	qDebug() << "Showing sequence!";
}


void SimonSaysUI::checkSequence()
{
	qDebug() << "Checking sequence!";
}

void SimonSaysUI::updateScore()
{
	qDebug() << "Updating score!";
}

void SimonSaysUI::updateHighScore()
{
	qDebug() << "Updating highscore!";
}

void SimonSaysUI::resetScore()
{
	qDebug() << "Resetting score!";
}

void SimonSaysUI::resetHighScore()
{
	qDebug() << "Resetting highscore!";
}

void SimonSaysUI::incrementScore()
{
	qDebug() << "Incrementing score!";
}

void SimonSaysUI::incrementHighScore()
{
	qDebug() << "Incrementing highscore!";
}