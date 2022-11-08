#include "Quaternion.h"

#pragma region constructor
Quaternion::Quaternion(const float _x, const float _y, const float _z, const float _w)
{
    x = _x;
    y = _y;
    z = _z;
    w = _w;
}
Quaternion::Quaternion(const float _value)
{
    x = y = z = w = _value;
}
Quaternion::Quaternion(const Quaternion& _copy)
{
    x = _copy.x;
    y = _copy.y;
    z = _copy.z;
    w = _copy.w;
}
#pragma endregion
#pragma region methods
Quaternion Quaternion::Identity()
{
    return Quaternion();
}
Quaternion Quaternion::Normalize(Quaternion _q)
{
    return Quaternion();
}
Quaternion Quaternion::Conjugate(Quaternion _value)
{
    return Quaternion();
}
Quaternion Quaternion::Inverse(Quaternion _rotation)
{
    return Quaternion();
}
Quaternion Quaternion::Negate(Quaternion _value)
{
    return Quaternion();
}
Quaternion Quaternion::Lerp(Quaternion _a, Quaternion _b, float _t)
{
    return Quaternion();
}
float Quaternion::Dot(Quaternion _a, Quaternion _b)
{
    return 0.0f;
}
Quaternion Quaternion::CreateFromYawpitchRoll(float _yaw, float _pitch, float _roll)
{
    return Quaternion();
}
float Quaternion::Angle(Quaternion _a, Quaternion _b)
{
    return 0.0f;
}
float Quaternion::Length()
{
    return 0.0f;
}
float Quaternion::LengthSquared()
{
    return 0.0f;
}
#pragma endregion
#pragma region operator
float& Quaternion::operator[](const int _index)
{
    switch (_index)
    {
    case 0:
        return x;
    case 1:
        return y;
    case 2:
        return z;
    case 3:
        return w;
    };
}
Quaternion Quaternion::operator+(const Quaternion& _other) const
{
    return Quaternion(x + _other.x, y + _other.y, z + _other.z, w + _other.w);
}
Quaternion Quaternion::operator-(const Quaternion& _other) const
{
    return Quaternion(x - _other.x, y - _other.y, z - _other.z, w - _other.w);
}
Quaternion Quaternion::operator*(const Quaternion& _other) const
{
    return Quaternion(x * _other.x, y * _other.y, z * _other.z, w * _other.w);
}
Quaternion Quaternion::operator/(const Quaternion& _other) const
{
    return Quaternion(x / _other.x, y / _other.y, z / _other.z, w / _other.w);
}
bool Quaternion::operator==(const Quaternion& _other) const
{
    return x == _other.x && y == _other.y && z == _other.z && w == _other.w;
}
bool Quaternion::operator!=(const Quaternion& _other) const
{
    return x != _other.x && y != _other.y && z != _other.z && w != _other.w;
}
Quaternion Quaternion::operator=(const Quaternion& _other)
{
    x = _other.x;
    y = _other.y;
    z = _other.z;
    w = _other.w;
    return *this;
}
#pragma endregion
