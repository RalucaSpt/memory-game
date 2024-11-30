#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GameUI.h"
#include "ScoreBoard.h"
#include "..\GameLogic\Game.h"

class GameUI : public QMainWindow
{
    Q_OBJECT

public:
    GameUI(QWidget *parent = nullptr);
    ~GameUI();

private:
    Ui::GameUIClass ui;

	Scoreboard* m_scoreboard;
	gameLogic::Game* m_game;


	QPushButton* m_redButton;
	QPushButton* m_yellowButton;
	QPushButton* m_blueButton;
	QPushButton* m_greenButton;



public slots:

	void startGame();
	void endGame();  
	void showSequence();
	void checkSequence();
	void updateScore(); 
	void updateHighScore();
	void resetScore(); 
	void resetHighScore(); 
	
	//void incrementScore(); 
	//void incrementHighScore(); 

};
