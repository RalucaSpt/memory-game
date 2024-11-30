#include "Scoreboard.h"

Scoreboard::Scoreboard(QLabel* score, QLabel* highScore, QObject* parent) 
	: QObject(parent), score(0), highScore(0) 
{	
	scoreLabel = new QLabel("Score: 0");
	highScoreLabel = new QLabel("Highscore: 0");
}

QLabel* Scoreboard::getScoreLabel() const {
	return scoreLabel;
}

QLabel* Scoreboard::getHighScoreLabel() const {
	return highScoreLabel;
}

int Scoreboard::getScore() const {
	return score;
}

int Scoreboard::getHighScore() const {
	return highScore;
}

void Scoreboard::setScore(int score) {
	this->score = score;
	scoreLabel->setText("Score: " + QString::number(score));
}

void Scoreboard::setHighScore(int highScore) {
	this->highScore = highScore;
	highScoreLabel->setText("Highscore: " + QString::number(highScore));
}

void Scoreboard::incrementScore() {
	setScore(score + 1);
}

void Scoreboard::incrementHighScore() {
	setHighScore(highScore + 1);
}