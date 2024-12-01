#pragma once

#include "Observable.h"
#include "Color.h"
#include <vector>

namespace gameLogic {

    class Game : public Observable
    {
    public:
        Game();

        // Joc
        void StartNewGame();
        std::vector<Color> RandomColorGenerator();
        bool VerifyPlayerMoveSequence(Color playerMove);
        bool CheckNewRecord();

        // Accesori
        const std::vector<Color>& GetMoveSequence() const;
        int GetMaxScore() const;
        int AddLevel();
        int GetPlayerMove() const;

        // Resetări și incrementări
        void ResetPlayerMove();
        //void IncrementPlayerMove();

    private:
        int m_level;
        std::vector<Color> m_moveSequence;
        int m_maxScore;
        int m_playerCurrentMoveNumber;
    };

} 
