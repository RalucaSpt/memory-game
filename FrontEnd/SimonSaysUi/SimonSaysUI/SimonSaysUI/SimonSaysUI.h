#ifndef SIMONSAYSUI_H
#define SIMONSAYSUI_H

#include <QMainWindow>
#include "ui_SimonSaysUI.h"
#include "Buttons.h"
#include "Scoreboard.h"

class SimonSaysUI : public QMainWindow {
    Q_OBJECT

private:
    Ui::SimonSaysUIClass ui;       // Interfața generată din fișierul .ui
    Buttons* buttons;         // Instanța clasei Buttons

	Scoreboard* scoreboard;   // Instanța clasei Scoreboard
	void setupConnections(); // Metodă pentru conectarea semnalelor butoanelor la sloturi

public:
    explicit SimonSaysUI(QWidget* parent = nullptr);
	~SimonSaysUI();

public slots:
	void startGame(); // Slot pentru începerea jocului
	void endGame();   // Slot pentru terminarea jocului
	void showSequence(); // Slot pentru afișarea secvenței
	void checkSequence(); // Slot pentru verificarea secvenței
	void updateScore(); // Slot pentru actualizarea scorului
	void updateHighScore(); // Slot pentru actualizarea highscore-ului
	void resetScore(); // Slot pentru resetarea scorului
	void resetHighScore(); // Slot pentru resetarea highscore-ului
	void incrementScore(); // Slot pentru incrementarea scorului
	void incrementHighScore(); // Slot pentru incrementarea highscore-ului
};

#endif // SIMONSAYSUI_H
