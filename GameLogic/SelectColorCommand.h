#pragma once
#include <memory>

#include "ICommand.h"
#include "EColor.h"

using GamePtr = std::shared_ptr<class Game>;

class SelectColorCommand : public ICommand
{
public:
	SelectColorCommand(GamePtr game, EColor color);

	void Execute() override;
	void Undo() override;

private:
	GamePtr m_game;
	EColor m_color;
};
