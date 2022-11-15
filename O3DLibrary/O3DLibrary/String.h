#pragma once
#include "Object.h"
#include <ostream>

namespace Core
{
	namespace PrimitiveType
	{
		class String sealed : public Object
		{
#pragma region f/p
		private:
			const char* value = "";
			int length = 0;
		public:
			static const String Empty;
#pragma endregion
#pragma region constructor
		public:
			String() = default;
			String(const char* _value);
			String(const String& _copy);
			String(std::string::iterator _begin, std::string::iterator _end);
#pragma endregion
#pragma region methods
		public:
			void Append(const String& _str);
			void Append(const char _value);
			int Length() const;
			const char* ToCstr() const;
#pragma endregion
#pragma region override
		public:
			String ToString() const override;
#pragma endregion

#pragma region operator
		public:
			operator const char* () const;
			friend std::ostream& operator>>(std::ostream& _os, const String& _str);
#pragma endregion
		};
	}
}
