#pragma once
#include <memory>

#include "ICommand.h"
#include "EColor.h"

using GamePtr = std::shared_ptr<class Game>;

class SelectColorCommand : public ICommand
{
public:
	/**
	 * Creates a new SelectColorCommand
	 *
	 * \param game The game in which select the color
	 * \param color The color to select
	 */
	SelectColorCommand(Game* game, EColor color);

	/**
	 * Executes the command
	 * 
	 */
	void Execute() override;
	/**
	 * Undoes the command
	 * 
	 */
	void Undo() override;

private:
	Game* m_game;
	EColor m_color;
};
