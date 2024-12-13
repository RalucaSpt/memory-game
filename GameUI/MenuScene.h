#pragma once

#include <QtWidgets/QFrame>
#include <QPushButton>
#include <QComboBox>
#include "EDifficulty.h"

class MenuScene : public QWidget
{
	Q_OBJECT

public:
	MenuScene(QWidget* parent = nullptr);
	~MenuScene() override = default;

	void showEvent(QShowEvent* event) override;

signals:
	void StartButtonPressed(EDifficulty difficulty);
	void QuitButtonPressed();

private:
	bool m_firstShow;
	QPushButton* m_startGameButton;
	QPushButton* m_quitButton;
	QComboBox* m_difficultyComboBox;
};
