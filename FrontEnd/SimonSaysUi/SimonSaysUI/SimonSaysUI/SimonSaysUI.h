#ifndef SIMONSAYSUI_H
#define SIMONSAYSUI_H

#include <QMainWindow>
#include "ui_SimonSaysUI.h"
#include "Buttons.h"

class SimonSaysUI : public QMainWindow {
    Q_OBJECT

private:
    Ui::SimonSaysUIClass ui;       // Interfața generată din fișierul .ui
    Buttons* buttons;         // Instanța clasei Buttons

public:
    explicit SimonSaysUI(QWidget* parent = nullptr);
};

#endif // SIMONSAYSUI_H
