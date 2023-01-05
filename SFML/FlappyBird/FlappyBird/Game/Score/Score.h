#pragma once
#include "../../Interface/IDrawable.h"

class Score : public IDrawable
{
#pragma region f/p
private:
	int score = 0;
#pragma endregion
#pragma region constructor
public:
	Score() = default;
	~Score() override = default;
#pragma endregion
#pragma region override
public:
	virtual void Update() override;
#pragma endregion
#pragma region operator
public:
	operator int() const;
	Score& operator=(const int _value);
	Score& operator+=(const int _value);
#pragma endregion

};

