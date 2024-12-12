#pragma once
#include <memory>
#include <vector>

#include "EColor.h"

using GameListenerWeakPtr = std::weak_ptr<class IGameListener>;
using Listeners = std::vector<GameListenerWeakPtr>;

class IGameListener
{
public:
	/**
	 * abstract: Called when a color is received
	 *
	 * \param color The color received
	 */
	virtual void OnColorReceived(EColor color) = 0;
	/**
	 * abstract: Called when the sequence blinking ends
	 * 
	 */
	virtual void OnSequenceEnd() = 0;
	/**
	 * abstract: Called when the score changes
	 *
	 * \param score The new score
	 */
	virtual void OnScoreChanged(int score) = 0;
	/**
	 * abstract: Called when the round ends
	 * 
	 */
	virtual void OnRoundEnded() = 0;
	/**
	 * abstract: Called when the game ends
	 *
	 */
	virtual void OnGameEnded() = 0;
};
