#include "SelectColorCommand.h"

#include "Game.h"

SelectColorCommand::SelectColorCommand(GamePtr game, EColor color)
	: m_game{ game }
	, m_color{ color }
{}

void SelectColorCommand::Execute()
{
	m_game->AddColor(m_color);
}

void SelectColorCommand::Undo()
{
	m_game->RemoveColor();
}
