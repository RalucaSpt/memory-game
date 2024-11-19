#pragma once
#include <random>
#include "Observable.h"
#define DEFAULT_SEQUENCE_LENGHT 8;


namespace gameLogic
{

	class Game : public Observable
	{
	public:
		Game();

		void StartGame();
		void MakeMove();

		std::vector<unsigned char> GetMoveSequence();
		bool VerifyPlayerMoveSequence(unsigned char playerMove);

	private:
		int m_sequenceLenght;
		std::vector<unsigned char> m_moveSequence;
		
		
		int m_playerMoveNumber;
	};

}
