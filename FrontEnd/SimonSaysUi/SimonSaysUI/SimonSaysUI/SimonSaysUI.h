#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SimonSaysUI.h"

class SimonSaysUI : public QMainWindow
{
    Q_OBJECT

public:
    SimonSaysUI(QWidget *parent = nullptr);
    ~SimonSaysUI();

private:
    Ui::SimonSaysUIClass ui;
};
