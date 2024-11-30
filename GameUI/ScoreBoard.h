
#include <qobject.h>
#include <QWidget>
#include <QLabel>

class Scoreboard : public QObject {
	Q_OBJECT
private:
	QLabel* scoreLabel; // Referință către label-ul pentru scor
	int score; // Scorul curent
	QLabel* highScoreLabel; // Referință către label-ul pentru highscore
	int highScore; // Highscore-ul curent

public:
	explicit Scoreboard(QLabel* score, QLabel* highScore, QObject* parent = nullptr);

	// Metode pentru acces la label-uri
	QLabel* getScoreLabel() const;
	QLabel* getHighScoreLabel() const;

	// Metode pentru acces la scoruri
	int getScore() const;
	int getHighScore() const;

	// Metode pentru setarea scorurilor
	void setScore(int score);
	void setHighScore(int highScore);

	// Metode pentru incrementarea scorurilor
	void incrementScore();
	void incrementHighScore();
};


