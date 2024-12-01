#pragma once
#include <qobject.h>
#include <QWidget>
#include <QLabel>

class Scoreboard : public QObject {
	Q_OBJECT
private:
	QLabel* scoreLabel;
	int score;
	QLabel* highScoreLabel; 
	int highScore;

public:
	explicit Scoreboard(QLabel* score, QLabel* highScore, QObject* parent = nullptr);

	QLabel* getScoreLabel() const;
	QLabel* getHighScoreLabel() const;

	int getScore() const;
	int getHighScore() const;

	void setScore(int score);
	void setHighScore(int highScore);

	void incrementScore();
	void incrementHighScore();
};


