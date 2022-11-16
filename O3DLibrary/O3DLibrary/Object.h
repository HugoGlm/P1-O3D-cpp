#pragma once
#include <iostream>
#include "O3DLibrary.h"

namespace Core
{
	namespace PrimitiveType
	{
		class FString;
		class Boolean;
	}
	class Object
	{
#pragma region constructor
	public:
		Object() = default;
		virtual ~Object() = default;
#pragma endregion
#pragma region methods
	public:
		O3DLIBRARY_API virtual Core::PrimitiveType::Boolean Equals(const Object* _obj) const;
		O3DLIBRARY_API virtual Core::PrimitiveType::FString ToString() const;
#pragma endregion
	};
	typedef Object* object;
}