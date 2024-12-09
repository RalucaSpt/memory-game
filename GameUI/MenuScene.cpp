#include "MenuScene.h"

MenuScene::MenuScene(QWidget* parent) :
	QWidget(parent),
	m_firstShow{ true },
	m_startGameButton{ new QPushButton() },
	m_quitButton{ new QPushButton() }
{
}

void MenuScene::showEvent(QShowEvent* event)
{
	if (m_firstShow)
	{
		m_startGameButton = findChild<QPushButton*>("startButton");
		m_quitButton = findChild<QPushButton*>("quitButton");

		QObject::connect(m_startGameButton, &QPushButton::released, this, [this]()
			{
				emit OnStartButtonPressed();
			});
		QObject::connect(m_quitButton, &QPushButton::released, this, [this]()
			{
				emit OnQuitButtonPressed();
			});

		m_firstShow = false;
	}
}
