#pragma once

#include "ui_GameUI.h"
#include "../GameLogic/Game.h"
#include "../GameLogic/IGameListener.h"

class GameUI : public QMainWindow, public IGameListener
{
	Q_OBJECT

public:
	explicit GameUI(Game* game, QWidget* parent = nullptr);
	~GameUI() override;

	// Implementare IGameListener
	void OnPressStart() override;
	void OnMoveMade() override;

private:
	Ui::GameUIClass ui;
	Game* m_game;
	int m_difficultyDilay;

	// Metode auxiliare
	QPushButton* getButtonForColor(Color color) const;
	Color getColorForButton(QPushButton* button) const;

	void setButtonsEnabled(bool enabled);

	// Logica UI
	void showSequence();
	void highlightButton(Color color);

private slots:
	void handleButtonPress();
	void on_startButton_clicked();
	void on_resetButton_clicked();
	void startGame();
};
