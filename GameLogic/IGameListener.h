#pragma once

//this will later be inplemented by the UI, which will become the observer
class IGameListener
{
public:
	virtual void OnPressStart() = 0;
	virtual void OnMoveMade() = 0;

	~IGameListener() = default;

};