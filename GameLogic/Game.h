#pragma once

#include "Observable.h"
#include "Color.h"
#include <vector>

namespace gameLogic
{
	class Game : public Observable
	{
	public:
		Game();

		void StartNewGame();
		void MakeMove(Color color);

		const std::vector<Color>& GetMoveSequence() const;
		int GetMaxScore() const;
		int GetLevel() const;
		int GetPlayerMove() const;
		bool IsGameOver() const;
		bool IsSequenceOver() const;

		void SetIsSequenceOver(bool isSequenceOver);

		int AddLevel();
		std::vector<Color> RandomColorGenerator();

		void ResetPlayerMove();

		bool VerifyPlayerMoveSequence(Color playerMove);
		bool CheckNewRecord();

	private:
		int m_score;
		std::vector<Color> m_moveSequence;
		int m_maxScore;
		int m_playerCurrentMoveNumber;

		bool m_isGameOver;
		bool m_isSequenceOver;
	};
}
