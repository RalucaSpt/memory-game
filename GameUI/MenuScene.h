#pragma once

#pragma once

#include <QtWidgets/QFrame>
#include <QPushButton>

class MenuScene : public QWidget
{
	Q_OBJECT

public:
	MenuScene(QWidget* parent = nullptr);
	~MenuScene() override = default;

	void showEvent(QShowEvent* event) override;

signals:
	void OnStartButtonPressed();
	void OnQuitButtonPressed();

private:
	bool m_firstShow;
	QPushButton* m_startGameButton;
	QPushButton* m_quitButton;
};
