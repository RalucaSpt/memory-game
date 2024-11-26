#include "SimonSaysUI.h"

void SimonSaysUI::setupConnections()
{
    // Creează instanța clasei Buttons
    buttons = new Buttons(ui.blueButton, ui.greenButton, ui.redButton, ui.yellowButton, this);

    // Exemplu: conectare semnal pentru butonul roșu
    connect(buttons->getRedButton(), &QPushButton::clicked, this, []() {
        qDebug() << "Red button clicked in SimonSaysUI!";
        });

	// Exemplu: conectare semnal pentru butonul albastru
	connect(buttons->getBlueButton(), &QPushButton::clicked, this, []() {
		qDebug() << "Blue button clicked in SimonSaysUI!";
		});

	// Exemplu: conectare semnal pentru butonul galben
	connect(buttons->getYellowButton(), &QPushButton::clicked, this, []() {
		qDebug() << "Yellow button clicked in SimonSaysUI!";
		});

	// Exemplu: conectare semnal pentru butonul verde
	connect(buttons->getGreenButton(), &QPushButton::clicked, this, []() {
		qDebug() << "Green button clicked in SimonSaysUI!";
		});

	// Creează instanța clasei Scoreboard
	scoreboard = new Scoreboard(ui.scoreLabel, ui.highScoreLabel, this);

	// Exemplu: conectare semnal pentru incrementarea scorului
	connect(ui.incrementScoreButton, &QPushButton::clicked, scoreboard, &Scoreboard::incrementScore);


}

SimonSaysUI::SimonSaysUI(QWidget* parent)
    : QMainWindow(parent), buttons(nullptr) {
    // Inițializează interfața grafică definită în .ui
    ui.setupUi(this);

    // Configurează fereastra
    setWindowTitle("Simon Says");
    resize(800, 800);
}
