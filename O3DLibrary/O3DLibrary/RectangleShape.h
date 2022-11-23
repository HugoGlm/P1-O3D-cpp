#pragma once
#include "Shape.h"

namespace Core
{
	class RectangleShape : public Shape
	{
#pragma region f/p
	private:
		int width = 20;
		int height = 10;
#pragma endregion
#pragma region constructor
	public:
		O3DLIBRARY_API RectangleShape(Position _position, int _width, int _height);
#pragma endregion
#pragma region methods
	public:
		O3DLIBRARY_API void Draw(HDC _hdc) override;
#pragma endregion

	};
}

