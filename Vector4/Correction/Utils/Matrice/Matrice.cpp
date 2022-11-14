#include "Matrice.h"
#include "../Macro/AssertMacro.h"
#include "../Quaternion/Quaternion.h"
#include "../Mathf/Mathf.h"

#pragma region constructor
Matrice::Matrice(float _m11, float _m12, float _m13, float _m14, float _m21, float _m22, float _m23, float _m24, float _m31, float _m32, float _m33, float _m34, float _m41, float _m42, float _m43, float _m44)
{
	m11 = _m11;
	m12 = _m12;
	m13 = _m13;
	m14 = _m14;
	m21 = _m21;
	m22 = _m22;
	m23 = _m23;
	m24 = _m24;
	m31 = _m31;
	m32 = _m32;
	m33 = _m33;
	m34 = _m34;
	m41 = _m41;
	m42 = _m42;
	m43 = _m43;
	m44 = _m44;
}
Matrice::Matrice(const Matrice& _copy)
{
	m11 = _copy.m11;
	m12 = _copy.m12;
	m13 = _copy.m13;
	m14 = _copy.m14;
	m21 = _copy.m21;
	m22 = _copy.m22;
	m23 = _copy.m23;
	m24 = _copy.m24;
	m31 = _copy.m31;
	m32 = _copy.m32;
	m33 = _copy.m33;
	m34 = _copy.m34;
	m41 = _copy.m41;
	m42 = _copy.m42;
	m43 = _copy.m43;
	m44 = _copy.m44;
}
#pragma endregion

#pragma region methods
std::string Matrice::ToString()
{
	return std::format("(m11: {} m12: {} m13: {} m14: {}) (m21: {} m22: {} m23: {} m24: {}) (m31: {} m32: {} m33: {} m34: {}) (m41: {} m42: {} m43: {} m44: {})", m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44);
}
Matrice Matrice::Identity()
{
	return Matrice(1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}
Matrice Matrice::CreateTranslation(const float _x, const float _y, const float _z)
{
	return Matrice(1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		_x, _y, _z, 1.0f
	);
}
Matrice Matrice::CreateScale(const float _x, const float _y, const float _z)
{
	return Matrice();
}
Matrice Matrice::CreateRotationX(const float _rads)
{
	float _a = Mathf::Cos(_rads);
	float _b = Mathf::Sin(_rads);
	return Matrice(1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, _a, _b, 0.0f,
		0.0f, _b, _a, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}
Matrice Matrice::CreateRotationY(const float _rads)
{
	float _a = Mathf::Cos(_rads);
	float _b = Mathf::Sin(_rads);
	return Matrice(_a, 0.0f, _b, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		_b, 0.0f, _a, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}
Matrice Matrice::CreateRotationZ(const float _rads)
{
	float _a = Mathf::Cos(_rads);
	float _b = Mathf::Sin(_rads);
	return Matrice(_a, _b, 0.0f, 0.0f,
		_b, _a, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}
Matrice Matrice::CreateOrthographic(const float _width, const float _height, const float _zNearPlane, const float _zFarPlane)
{
	float _ratio = _width / _height;
	float _a = 1.0f / (_ratio * Mathf::Tan(Epsilon / 2));
	float _b = 1.0f / (Mathf::Tan(Epsilon / 2));
	float _c = (_zNearPlane + _zFarPlane) / (_zNearPlane - _zFarPlane);
	float _d = 2.0f * (_zNearPlane * _zFarPlane) / (_zNearPlane - _zFarPlane);
	return Matrice(_a, 0.0f, 0.0f, 0.0f,
		0.0f, _b, 0.0f, 0.0f,
		0.0f, 0.0f, _c, 0.0f,
		0.0f, 0.0f, _d, 0.0f
	);
}
Matrice Matrice::CreateFromQuaternion(const Quaternion _quaternion)
{
	return Matrice();
}
Matrice Matrice::Lerp(const Matrice& _matrice1, const Matrice& _matrice2, float _amount)
{
	return Matrice(
		_matrice1.m11 + (_matrice2.m11 - _matrice1.m11) * _amount,
		_matrice1.m12 + (_matrice2.m12 - _matrice1.m12) * _amount,
		_matrice1.m13 + (_matrice2.m13 - _matrice1.m13) * _amount,
		_matrice1.m14 + (_matrice2.m14 - _matrice1.m14) * _amount,
		_matrice1.m21 + (_matrice2.m21 - _matrice1.m21) * _amount,
		_matrice1.m22 + (_matrice2.m22 - _matrice1.m22) * _amount,
		_matrice1.m23 + (_matrice2.m23 - _matrice1.m23) * _amount,
		_matrice1.m24 + (_matrice2.m24 - _matrice1.m24) * _amount,
		_matrice1.m31 + (_matrice2.m31 - _matrice1.m31) * _amount,
		_matrice1.m32 + (_matrice2.m32 - _matrice1.m32) * _amount,
		_matrice1.m33 + (_matrice2.m33 - _matrice1.m33) * _amount,
		_matrice1.m34 + (_matrice2.m34 - _matrice1.m34) * _amount,
		_matrice1.m41 + (_matrice2.m41 - _matrice1.m41) * _amount,
		_matrice1.m42 + (_matrice2.m42 - _matrice1.m42) * _amount,
		_matrice1.m43 + (_matrice2.m43 - _matrice1.m43) * _amount,
		_matrice1.m44 + (_matrice2.m44 - _matrice1.m44) * _amount
	);
}
float Matrice::GetDeterminant() const
{
	return(m11 * m22 * m33 * m44) - (m11 * m22 * m34 * m43) - (m11 * m23 * m32 * m44) + (m11 * m23 * m34 * m42) + (m11 * m24 * m32 * m43) - (m11 * m24 * m33 * m42)
		- (m12 * m21 * m33 * m44) + (m12 * m21 * m34 * m43) + (m12 * m23 * m31 * m44) - (m12 * m23 * m34 * m41) - (m12 * m24 * m32 * m43) + (m12 * m24 * m33 * m42)
		+ (m13 * m21 * m32 * m44) - (m13 * m21 * m34 * m42) - (m13 * m22 * m31 * m44) + (m13 * m22 * m34 * m41) + (m13 * m24 * m31 * m42) - (m13 * m24 * m32 * m41)
		- (m14 * m21 * m32 * m43) + (m14 * m21 * m33 * m41) + (m14 * m22 * m31 * m43) - (m14 * m22 * m33 * m41) - (m14 * m23 * m31 * m42) + (m14 * m23 * m32 * m41);
}
#pragma endregion

#pragma region operator
Matrice Matrice::operator+(const Matrice& _other) const
{
	return Matrice(m11 + _other.m11, m12 + _other.m12, m13 + _other.m13, m14 + _other.m14, m21 + _other.m21, m22 + _other.m22, m23 + _other.m23, m24 + _other.m24, m31 + _other.m31, m32 + _other.m32, m33 + _other.m33, m34 + _other.m34, m41 + _other.m41, m42 + _other.m42, m43 + _other.m43, m44 + _other.m44);
}
Matrice Matrice::operator*(const Matrice& _other) const
{
	return Matrice(
		(m11 * _other.m11) + (m12 * _other.m21) + (m13 * _other.m31) + (m14 * _other.m41),
		(m11 * _other.m12) + (m12 * _other.m22) + (m13 * _other.m32) + (m14 * _other.m42),
		(m11 * _other.m13) + (m12 * _other.m23) + (m13 * _other.m33) + (m14 * _other.m43),
		(m11 * _other.m14) + (m12 * _other.m24) + (m13 * _other.m34) + (m14 * _other.m44),
		(m21 * _other.m11) + (m22 * _other.m21) + (m23 * _other.m31) + (m24 * _other.m41),
		(m21 * _other.m12) + (m22 * _other.m22) + (m23 * _other.m32) + (m24 * _other.m42),
		(m21 * _other.m13) + (m22 * _other.m23) + (m23 * _other.m33) + (m24 * _other.m43),
		(m21 * _other.m14) + (m22 * _other.m24) + (m23 * _other.m34) + (m24 * _other.m44),
		(m31 * _other.m11) + (m32 * _other.m21) + (m33 * _other.m31) + (m34 * _other.m41),
		(m31 * _other.m12) + (m32 * _other.m22) + (m33 * _other.m32) + (m34 * _other.m42),
		(m31 * _other.m13) + (m32 * _other.m23) + (m33 * _other.m33) + (m34 * _other.m43),
		(m31 * _other.m14) + (m32 * _other.m24) + (m33 * _other.m34) + (m34 * _other.m44),
		(m41 * _other.m11) + (m42 * _other.m21) + (m43 * _other.m31) + (m44 * _other.m41),
		(m41 * _other.m12) + (m42 * _other.m22) + (m43 * _other.m32) + (m44 * _other.m42),
		(m41 * _other.m13) + (m42 * _other.m23) + (m43 * _other.m33) + (m44 * _other.m43),
		(m41 * _other.m14) + (m42 * _other.m24) + (m43 * _other.m34) + (m44 * _other.m44)
	);
}
Matrice Matrice::operator-(const Matrice& _other) const
{
	return Matrice(m11 - _other.m11, m12 - _other.m12, m13 - _other.m13, m14 - _other.m14, m21 - _other.m21, m22 - _other.m22, m23 - _other.m23, m24 - _other.m24, m31 - _other.m31, m32 - _other.m32, m33 - _other.m33, m34 - _other.m34, m41 - _other.m41, m42 - _other.m42, m43 - _other.m43, m44 - _other.m44);
}
Matrice Matrice::operator-() const
{
	return Matrice();
}
float& Matrice::operator[](const int _index)
{
	check(_index > 0 || _index < 4);
	switch (_index)
	{
	case 0:
		return m11;
	case 1:
		return m12;
	case 2:
		return m13;
	case 3:
		return m14;
	case 4:
		return m21;
	case 5:
		return m22;
	case 6:
		return m23;
	case 7:
		return m24;
	case 8:
		return m31;
	case 9:
		return m32;
	case 10:
		return m33;
	case 11:
		return m34;
	case 12:
		return m41;
	case 13:
		return m42;
	case 14:
		return m43;
	case 15:
		return m44;
	};
}
#pragma endregion
