#pragma once
class IGameListener
{
public:
	virtual void OnPressStart() = 0;
	virtual void OnMoveMade() = 0;

	~IGameListener() = default;

};