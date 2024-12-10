#include "MenuScene.h"

MenuScene::MenuScene(QWidget* parent) :
	QWidget(parent),
	m_firstShow{ true },
	m_startGameButton{ new QPushButton() },
	m_quitButton{ new QPushButton() },
	m_difficultyComboBox { new QComboBox() }
{
}

void MenuScene::showEvent(QShowEvent* event)
{
	if (m_firstShow)
	{
		m_startGameButton = findChild<QPushButton*>("startButton");
		m_quitButton = findChild<QPushButton*>("quitButton");
		m_difficultyComboBox = findChild<QComboBox*>("difficultyComboBox");

		QObject::connect(m_startGameButton, &QPushButton::released, this, [this]()
			{
				emit StartButtonPressed(static_cast<EDifficulty>(m_difficultyComboBox->currentIndex()));
			});
		QObject::connect(m_quitButton, &QPushButton::released, this, [this]()
			{
				emit QuitButtonPressed();
			});

		m_firstShow = false;
	}
}
