#pragma once

#include <QtWidgets/QFrame>
#include <QPushButton>
#include <QLCDNumber>
#include "ColorsFrame.h"

class GameScene : public QWidget
{
	Q_OBJECT

public:
	GameScene(QWidget* parent = nullptr);
	~GameScene() override = default;

	void showEvent(QShowEvent* event) override;

signals:
	void OnBackToMainMenuButtonPressed();

private:
	bool m_firstShow;
	QLCDNumber* m_bestScore;
	QLCDNumber* m_currentScore;
	QPushButton* m_backToMainMenu;
	ColorsFrame* m_colorsFrame;
};
