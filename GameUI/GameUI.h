#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GameUI.h"
#include "ScoreBoard.h"
#include "..\GameLogic\Game.h"
#include "..\GameLogic\IGameListener.h"


class GameUI : public QMainWindow, public gameLogic::IGameListener
{
    Q_OBJECT

public:
    GameUI(gameLogic::Game* game, QWidget *parent = nullptr);
    ~GameUI();

	// Implementare IGameListener
	void OnPressStart() override;
	void OnMoveMade() override;

private:
    Ui::GameUIClass ui;

	gameLogic::Game* m_game;
	Scoreboard* m_scoreboard;


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

	void OnColorGenerated(gameLogic::Color color); // Afișează culoarea

	
	//void incrementScore(); 
	//void incrementHighScore(); 

};
