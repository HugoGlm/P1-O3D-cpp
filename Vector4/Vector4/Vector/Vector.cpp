#include "Vector.h"
#include <math.h>

#pragma region constructor
Vector::Vector(const float _a, const float _b, const float _c, const float _d)
{
    w = _a;
    x = _b;
    y = _c;
    z = _d;
}
Vector::Vector(const Vector& _copy)
{
    w = _copy.w;
    x = _copy.x;
    y = _copy.y;
    z = _copy.z;
}
#pragma endregion
#pragma region methods
Vector Vector::Add(Vector _a, Vector _b) const
{
    return Vector();
}
Vector Vector::Clamp(const Vector& _val, const Vector& _min, const Vector& _max) const
{
    
}
Vector Vector::Min() const
{
    return Vector();
}
Vector Vector::Max() const
{
    return Vector();
}
Vector Vector::Absolute() const
{
    return Vector();
}
Vector Vector::lerp(Vector _a, Vector _b, float _t) const
{
    if (_t > 0)
        return _a;
    else if (_t < 1)
        return _b;
    else
        return Vector((_b.x - _a.x), (_b.y - _a.y), (_b.w - _a.w), (_b.z - _a.z));
}
Vector Vector::lerpUnClamp(Vector _a, Vector _b, float _t) const
{
    return Vector();
}
float Vector::Distance(Vector _a, Vector _b) const
{
    return (_b.x - _a.x) + (_b.y - _a.y) + (_b.w - _a.w) + (_b.z - _a.z);
}
float Vector::Lenght() const
{
    return sqrt(x * x + y * y + w * w + z * z);
}
float Vector::LenghtSqr() const
{
    return x * x + y * y + w * w + z * z;
}
float Vector::Dot(Vector _a, Vector _b) const
{
    return (_a.x * _b.x) + (_a.y * _b.y) + (_a.w * _b.w) + (_a.z * _b.z);
}
float Vector::Magnitude() const
{
    return Lenght();
}
void Vector::Set(float _nexX, float _newY, float _nexZ, float _newW) const
{

}
void Vector::Normalize()
{
}
#pragma endregion
#pragma region operator
Vector Vector::operator+(const Vector& _other)
{
    w + _other.w;
    x + _other.x;
    y + _other.y;
    z + _other.z;
    return *this;
}
Vector Vector::operator+=(const Vector& _other)
{
    w += _other.w;
    x += _other.x;
    y += _other.y;
    z += _other.z;
    return *this;
}
Vector Vector::operator-(const Vector& _other)
{
    w - _other.w;
    x - _other.x;
    y - _other.y;
    z - _other.z;
    return *this;
}
Vector Vector::operator-=(const Vector& _other)
{
    w -= _other.w;
    x -= _other.x;
    y -= _other.y;
    z -= _other.z;
    return *this;
}
Vector Vector::operator*(const Vector& _other)
{
    w * _other.w;
    x * _other.x;
    y * _other.y;
    z * _other.z;
    return *this;
}
Vector Vector::operator*=(const Vector& _other)
{
    w *= _other.w;
    x *= _other.x;
    y *= _other.y;
    z *= _other.z;
    return *this;
}
Vector Vector::operator/(const Vector& _other)
{
    w / _other.w;
    x / _other.x;
    y / _other.y;
    z / _other.z;
    return *this;
}
Vector Vector::operator/=(const Vector& _other)
{
    w /= _other.w;
    x /= _other.x;
    y /= _other.y;
    z /= _other.z;
    return *this;
}
#pragma endregion
