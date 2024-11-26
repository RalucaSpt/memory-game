#ifndef BUTTONS_H
#define BUTTONS_H

#include <QObject>
#include <QPushButton>
#include <QWidget>

class Buttons : public QObject {
    Q_OBJECT

private:
    QPushButton* redButton;    // Referință către butonul roșu
    QPushButton* blueButton;   // Referință către butonul albastru
    QPushButton* yellowButton; // Referință către butonul galben
    QPushButton* greenButton;  // Referință către butonul verde

public:
    explicit Buttons(QPushButton* red, QPushButton* blue, QPushButton* yellow, QPushButton* green, QObject* parent = nullptr);

    // Metode pentru acces la butoane individuale
    QPushButton* getRedButton() const;
    QPushButton* getBlueButton() const;
    QPushButton* getYellowButton() const;
    QPushButton* getGreenButton() const;
};

#endif // BUTTONS_H
