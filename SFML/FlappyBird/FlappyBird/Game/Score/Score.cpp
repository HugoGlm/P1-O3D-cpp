#include "Score.h"

#pragma region methods
void Score::Update()
{
	score++;
}
#pragma endregion

#pragma region override
Score::operator int() const
{
	return score;
}
Score& Score::operator=(const int _value)
{
	score = _value;
	return *this;
}
Score& Score::operator+=(const int _value)
{
	score += _value;
	return *this;
}
#pragma endregion

