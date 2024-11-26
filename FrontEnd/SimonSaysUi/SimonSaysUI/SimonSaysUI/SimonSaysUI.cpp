#include "SimonSaysUI.h"

SimonSaysUI::SimonSaysUI(QWidget* parent)
    : QMainWindow(parent), buttons(nullptr) {
    // Inițializează interfața grafică definită în .ui
    ui.setupUi(this);

    // Creează instanța clasei Buttons
    buttons = new Buttons(ui.blueButton, ui.greenButton, ui.redButton, ui.yellowButton, this);

    // Exemplu: conectare semnal pentru butonul roșu
    connect(buttons->getRedButton(), &QPushButton::clicked, this, []() {
        qDebug() << "Red button clicked in SimonSaysUI!";
        });

    // Configurează fereastra
    setWindowTitle("Simon Says");
    resize(800, 800);
}
