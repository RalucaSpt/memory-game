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
};

#endif // SIMONSAYSUI_H
