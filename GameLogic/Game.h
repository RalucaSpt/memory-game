#pragma once

#include "Observable.h"
#include "Color.h"
#include <vector>

namespace gameLogic {

    class Game : public Observable
    {
    public:
        Game();

        void StartNewGame();
        std::vector<Color> RandomColorGenerator();
        bool VerifyPlayerMoveSequence(Color playerMove);
        bool CheckNewRecord();

        const std::vector<Color>& GetMoveSequence() const;
        int GetMaxScore() const;
        int AddLevel();
        int GetPlayerMove() const;

        void ResetPlayerMove();

    private:
        int m_score;
        std::vector<Color> m_moveSequence;
        int m_maxScore;
        int m_playerCurrentMoveNumber;
    };

} 
