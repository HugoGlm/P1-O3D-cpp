#pragma once
#include "Singleton.h"
#include <vector>

class Button;

class EventSystem : public Singleton<EventSystem>
{
#pragma region f/p
private:
	std::vector<Button*> buttons = std::vector<Button*>();
#pragma endregion
#pragma region methods
public:
	void Register(Button* _button);
	void UnRegister(Button* _button);
	void Update();
	void Clear();
#pragma endregion
#pragma region override
public:
	void OnDestroy() override;
#pragma endregion

};

