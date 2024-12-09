#include "GameScene.h"

GameScene::GameScene(QWidget* parent) :
	QWidget(parent),
	m_firstShow{ true },
	m_bestScore{ new QLCDNumber() },
	m_currentScore{ new QLCDNumber() },
	m_colorsFrame{new ColorsFrame() }
{
}

void GameScene::showEvent(QShowEvent* event)
{
	if (m_firstShow)
	{
		m_bestScore = findChild<QLCDNumber*>("bestScore");
		m_currentScore = findChild<QLCDNumber*>("currentScore");
		m_colorsFrame = findChild<ColorsFrame*>("colorsFrame");
		m_backToMainMenu = findChild<QPushButton*>("mainMenuButton");

		QObject::connect(m_backToMainMenu, &QPushButton::released, this, [this]()
			{
				emit OnBackToMainMenuButtonPressed();
			});

		m_firstShow = false;
	}
}
