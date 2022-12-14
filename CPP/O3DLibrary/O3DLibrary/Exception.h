#pragma once
#include "Object.h"
#include "FString.h"
#include <source_location>

namespace Core
{
	class Exception : public Object
	{
#pragma region f/p
	private:
		Core::PrimitiveType::FString error = "";
#pragma endregion
#pragma region constructor
	public:
		O3DLIBRARY_API Exception(const Core::PrimitiveType::FString& _error = "exeption", const std::source_location& _location = std::source_location::current());
#pragma endregion
#pragma region override
	public:
		O3DLIBRARY_API Core::PrimitiveType::FString ToString() const override;
#pragma endregion
	};

	typedef Exception OutOfRangeException;
	typedef Exception DivideByZeroException;
}
