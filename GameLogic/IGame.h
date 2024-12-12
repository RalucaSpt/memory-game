#pragma once
#include <vector>
#include <memory>

#include "EColor.h"
#include "EDifficulty.h"
#include "IGameListener.h"

using IGamePtr = std::shared_ptr<class IGame>;

using ColorSequence = std::vector<EColor>;

using StrategyPtr = std::shared_ptr<class IStrategy>;

class IGame
{
public:
	/**
	 * Creates a new game with the specified difficulty and custom strategy
	 * 
	 * \param difficulty Difficulty of the game
	 * \param customStrategy The custom strategy to use
	 * \return The created game
	 * \return The created game
	 */
	static IGamePtr Produce(EDifficulty difficulty, StrategyPtr customStrategy = nullptr);

	/**
	 * abstract: Sets the strategy to use in the game
	 * 
	 * \param strategy The strategy to use
	 */
	virtual void SetStrategy(StrategyPtr strategy) = 0;

	/**
	 * abstract: Starts the game
	 * 
	 */
	virtual void StartGame() = 0;
	/**
	 * abstract: Stops the game
	 * 
	 */
	virtual void StopGame() = 0;

	/**
	 * abstract: Selects a color in the game
	 *
	 * \param color The color to select
	 */
	virtual void SelectColor(EColor color) = 0;

	/**
	 * abstract: Undoes the last color selection
	 *
	 */
	virtual void Undo() = 0;

	/**
	 * abstract: Checks whether the sequence is correct or not
	 *
	 */
	virtual void CheckSequence() = 0;

	/**
	 * abstract: Gets the current game sequence
	 *
	 * \return Vector with the sequence colors
	 */
	virtual ColorSequence GetCurrentSequence() = 0;
	
	/**
	 * abstract: Subscribes a listener to the game
	 * 
	 * \param listener The listener to subscribe
	 */
	virtual void Subscribe(GameListenerWeakPtr listener) = 0;

	/**
	 * abstract: Unsubscribes a listener from the game
	 *
	 * \param listener The listener to unsubscribe
	 */
	virtual void Unsubscribe(GameListenerWeakPtr listener) = 0;
};