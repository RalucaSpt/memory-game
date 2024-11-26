#include "Buttons.h"

Buttons::Buttons(QPushButton* blue, QPushButton* green, QPushButton* red, QPushButton* yellow, QObject* parent)
    : QObject(parent), blueButton(blue), greenButton(green), redButton(red), yellowButton(yellow) {
    // Exemplu: conectare semnale pentru fiecare buton
    connect(blueButton, &QPushButton::clicked, this, []() {
        qDebug() << "Blue button clicked!";
        });

    connect(greenButton, &QPushButton::clicked, this, []() {
        qDebug() << "Green button clicked!";
        });

    connect(redButton, &QPushButton::clicked, this, []() {
        qDebug() << "Red button clicked!";
        });

    connect(yellowButton, &QPushButton::clicked, this, []() {
        qDebug() << "Yellow button clicked!";
        });
}

// Metode pentru acces la butoane individuale
QPushButton* Buttons::getRedButton() const {
    return redButton;
}

QPushButton* Buttons::getBlueButton() const {
    return blueButton;
}

QPushButton* Buttons::getYellowButton() const {
    return yellowButton;
}

QPushButton* Buttons::getGreenButton() const {
    return greenButton;
}
