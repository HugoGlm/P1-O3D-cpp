#pragma once
#include "Object.h"
#include <limits>

namespace Core
{
	namespace PrimitiveType
	{
		class Boolean;
		class FString;
		class Integer sealed : public Object
		{
#pragma region var
		private:
			int value = 0;
		public:
			O3DLIBRARY_API static Integer MinValue();
			O3DLIBRARY_API static Integer MaxValue();
#pragma endregion

#pragma region const
		public:
			Integer() = default;
			O3DLIBRARY_API Integer(const int _val);
			O3DLIBRARY_API Integer(const Integer& _copy);
#pragma endregion

#pragma region methods
		public:
			O3DLIBRARY_API Boolean Equals(const Integer& _other) const;
			O3DLIBRARY_API static Integer Parse(const FString& _str);
			O3DLIBRARY_API static Boolean TryParse(const FString& _str, Integer& _out);
#pragma endregion

#pragma region override
		public:
			O3DLIBRARY_API FString ToString() const override;
			O3DLIBRARY_API Boolean Equals(const Object* _obj) const override;
#pragma endregion

#pragma region operator
		public:
			O3DLIBRARY_API operator int() const;
			O3DLIBRARY_API Integer operator+(const Integer& _other) const;
			O3DLIBRARY_API Integer operator++(int);
			O3DLIBRARY_API Integer operator++();
			O3DLIBRARY_API Integer& operator+=(const Integer& _other);
			O3DLIBRARY_API Integer operator--(int);
			O3DLIBRARY_API Integer operator--();
			O3DLIBRARY_API Integer operator-(const Integer& _other) const;
			O3DLIBRARY_API Integer& operator-=(const Integer& _other);
			O3DLIBRARY_API Integer operator*(const Integer& _other) const;
			O3DLIBRARY_API Integer& operator*=(const Integer& _other);
			O3DLIBRARY_API Integer operator/(const Integer& _other) const;
			O3DLIBRARY_API Integer& operator/=(const Integer& _other);
			O3DLIBRARY_API Integer operator%(const Integer& _other) const;
			O3DLIBRARY_API Integer& operator%=(const Integer& _other);
			O3DLIBRARY_API Integer operator-();
			O3DLIBRARY_API Boolean operator<(const Integer& _other) const;
			O3DLIBRARY_API Boolean operator<=(const Integer& _other) const;
			O3DLIBRARY_API Boolean operator>(const Integer& _other) const;
			O3DLIBRARY_API Boolean operator>=(const Integer& _other) const;
			O3DLIBRARY_API Boolean operator==(const Integer& _other) const;
			O3DLIBRARY_API Boolean operator!=(const Integer& _other) const;
#pragma endregion
		};
	}
}