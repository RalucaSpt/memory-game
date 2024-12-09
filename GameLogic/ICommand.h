#pragma once
#include <vector>
#include <memory>

using CommandSequence = std::vector<std::shared_ptr<class ICommand>>;

class ICommand
{
public:
	virtual void Execute() = 0;
	virtual void Undo() = 0;
};

