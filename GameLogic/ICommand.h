#pragma once
#include <vector>
#include <memory>

using CommandSequence = std::vector<std::shared_ptr<class ICommand>>;

class ICommand
{
public:
	/**
	 * abstract: Executes the command
	 * 
	 */
	virtual void Execute() = 0;
	/**
	 * abstract: Undoes the command
	 *
	 */
	virtual void Undo() = 0;
};

