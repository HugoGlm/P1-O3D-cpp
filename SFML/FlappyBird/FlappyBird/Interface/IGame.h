#pragma once
#include "../Object/Object.h"

class IGame : public Object
{
#pragma region constructor
public:
	virtual ~IGame() = default;
#pragma endregion
#pragma region methods
	public:
		virtual void OnStart() = 0; 
		virtual void OnUpdate() = 0;
		virtual void OnEnd() = 0;
		virtual void DisplayMenu() = 0;
#pragma endregion

};