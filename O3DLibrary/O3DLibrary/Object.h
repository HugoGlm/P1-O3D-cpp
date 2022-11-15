#pragma once
#include <string>

namespace Core
{
	namespace PrimitiveType
	{
		class String;
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
		virtual Core::PrimitiveType::String ToString() const;
#pragma endregion

	};
}


