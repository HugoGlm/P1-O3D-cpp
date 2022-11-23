#include "RectangleShape.h"

#pragma region constructor
Core::RectangleShape::RectangleShape(Position _position, int _width, int _height)
    : Shape(_position)
{
    width = _width;
    height = _height;
}
#pragma endregion

#pragma region methods
void Core::RectangleShape::Draw(HDC _hdc)
{
    Shape::Draw(_hdc);
    if (!IsValid())
        return;
    Gdiplus::SolidBrush brush(style.backgroundColor);
    graphics->FillRectangle(&brush, Gdiplus::Rect(position.x, position.y, width, height));
    /*int radius = 60;
    graphics->FillEllipse(&brush, Gdiplus::Rect(position.x, position.y, radius, radius));*/
}
#pragma endregion

