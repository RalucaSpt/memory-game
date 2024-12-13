#pragma once

#include "ui_GameUI.h"
#include "../GameLogic/Game.h"

class GameUI : public QMainWindow
{
	Q_OBJECT

public:
	GameUI(QWidget* parent = nullptr);
	~GameUI() override = default;

private:
	void SetupConnections();

private:
	Ui::GameUIClass ui;
};
