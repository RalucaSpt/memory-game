#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GameUI.h"
#include "..\GameLogic\Game.h"
#include "..\GameLogic\IGameListener.h"

class GameUI : public QMainWindow, public gameLogic::IGameListener
{
    Q_OBJECT

public:
    explicit GameUI(gameLogic::Game* game, QWidget* parent = nullptr);
    ~GameUI();

    // Implementare IGameListener
    void OnPressStart() override;
    void OnMoveMade() override;

private:
    Ui::GameUIClass ui;
    gameLogic::Game* m_game;
    int m_difficultyDilay;

    // Metode auxiliare
    QPushButton* getButtonForColor(gameLogic::Color color) const;
    gameLogic::Color getColorForButton(QPushButton* button) const;

    void setButtonsEnabled(bool enabled);

    // Logica UI
    void showSequence();
    void highlightButton(gameLogic::Color color);

private slots:
    void handleButtonPress();
	void on_startButton_clicked();
    void startGame();
};
