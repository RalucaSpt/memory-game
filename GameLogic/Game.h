#pragma once
#include <random>
#include "Observable.h"
#include "Color.h"


namespace gameLogic
{

	class Game : public Observable
	{
	public:
		Game();

		void StartNewGame();
		void MakeMove();

		std::vector<Color> RandomColorGenerator();
		bool VerifyPlayerMoveSequence(Color playerMove);
		//bool CheckNewRecord();

	private:
		int m_level;
		std::vector<Color> m_moveSequence;
		int m_maxScore;
		int m_playerCurrentMoveNumber;
	};

}
