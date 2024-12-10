#pragma once

#include "ui_GameUI.h"
#include "../GameLogic/Game.h"

class GameUI : public QMainWindow
{
	Q_OBJECT

public:
	GameUI(QWidget* parent = nullptr);
	~GameUI() override = default;

//private slots:
//	void HandleButtonPress();
//	void OnStartButtonClicked();
//	void on_resetButton_clicked();
//	void startGame();

private:
	void SetupConnections();

	/*QPushButton* GetButtonForColor(Color color) const;
	Color GetColorForButton(QPushButton* button) const;

	void SetButtonsEnabled(bool enabled);
	void ShowSequence();
	void HighlightButton(Color color);*/

private:
	Ui::GameUIClass ui;
	//Game* m_game;
	//int m_difficultyDilay;
};
