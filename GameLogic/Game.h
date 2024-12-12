#pragma once
#include <vector>
#include <functional>

#include "IGame.h"
#include "EColor.h"
#include "ICommand.h"
#include "EGameState.h"

using GamePtr = std::shared_ptr<class Game>;

using NotifyFunction = std::function<void(IGameListener*)>;

/**
 * \class Game
 * \brief Implements the IGame interface to manage the game logic.
 */
class Game : public IGame
{
public:
    /**
     * \brief Constructs a new Game object.
     */
    Game();

    /**
     * \brief Sets the strategy to use in the game.
     *
     * \param strategy The strategy to use.
     */
    void SetStrategy(StrategyPtr strategy) override;

    /**
     * \brief Starts the game.
     */
    void StartGame() override;

    /**
     * \brief Stops the game.
     */
    void StopGame() override;

    /**
     * \brief Selects a color in the game.
     *
     * \param color The color to select.
     */
    void SelectColor(EColor color) override;

    /**
     * \brief Undoes the last color selection.
     */
    void Undo() override;

    /**
     * \brief Checks whether the sequence is correct or not.
     */
    void CheckSequence() override;

    /**
     * \brief Gets the current game sequence.
     *
     * \return ColorSequence The current sequence of colors.
     */
    ColorSequence GetCurrentSequence() override;

    /**
     * \brief Subscribes a listener to the game.
     *
     * \param listener The listener to subscribe.
     */
    void Subscribe(GameListenerWeakPtr listener) override;

    /**
     * \brief Unsubscribes a listener from the game.
     *
     * \param listener The listener to unsubscribe.
     */
    void Unsubscribe(GameListenerWeakPtr listener) override;

    /**
     * \brief Adds a color to the sequence.
     *
     * \param color The color to add.
     */
    void AddColor(EColor color);

    /**
     * \brief Removes the last color from the sequence.
     */
    void RemoveColor();

private:
    /**
     * \brief Creates a new sequence of colors.
     */
    void CreateSequence();

    /**
     * \brief Proceeds to the next turn in the game.
     */
    void NextTurn();

    /**
     * \brief Ends the game.
     */
    void EndGame();

    /**
     * \brief Resets the game to its initial state.
     */
    void ResetGame();

    /**
     * \brief Verifies if the player's sequence matches the game sequence.
     *
     * \return true if the sequences match, false otherwise.
     */
    bool VerifyPlayerSequence();

    /**
     * \brief Notifies all listeners with a specific function.
     *
     * \param function The function to notify the listeners with.
     */
    void NotifyListeners(NotifyFunction function);

    /**
     * \brief Gets the notify function for when a color is received.
     *
     * \param color The color received.
     * \return NotifyFunction The notify function.
     */
    NotifyFunction GetNotifyColorReceived(EColor color);

    /**
     * \brief Gets the notify function for when the sequence ends.
     *
     * \return NotifyFunction The notify function.
     */
    NotifyFunction GetNotifySequenceEnd();

    /**
     * \brief Gets the notify function for when the score changes.
     *
     * \param index The new score index.
     * \return NotifyFunction The notify function.
     */
    NotifyFunction GetNotifyScoreChanged(int index);

    /**
     * \brief Gets the notify function for when a round ends.
     *
     * \return NotifyFunction The notify function.
     */
    NotifyFunction GetNotifyRoundEnded();

    /**
     * \brief Gets the notify function for when the game ends.
     *
     * \return NotifyFunction The notify function.
     */
    NotifyFunction GetNotifyGameEnded();

private:
    EGameState m_state;

    ColorSequence m_colorSequence;
    ColorSequence m_playerSequence;
    CommandSequence m_playerActions;

    StrategyPtr m_strategy;

    Listeners m_listeners;

    int m_score;

    bool m_stopping;
};
