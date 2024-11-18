#pragma once
#include <random>
#include "Observable.h"

class Game : public Observable
{
public:
	void StartGame();
	void MakeMove();

private:
	std::vector<unsigned char> GetMoveSequence();
	bool VerifyPlayerMoveSequence(std::vector<unsigned char> playerSequence);

private:
	std::vector<unsigned char> m_moveSequence;

};

