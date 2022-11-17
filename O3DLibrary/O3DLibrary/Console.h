#pragma once
#include "Object.h"
#include <Windows.h>
#include "EConsoleColor.h"

namespace Core
{
	namespace IO
	{
		class TextWritter;
	}
	class Console : public Object
	{
#pragma region f/p
	private:
		static inline HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	public:
		O3DLIBRARY_API static IO::TextWritter* Out;
#pragma endregion
#pragma region methods
	private:
		O3DLIBRARY_API static IO::TextWritter* Out_Internal();
	public:
		O3DLIBRARY_API static void WriteLine(const object _obj, const EConsoleColor& _color = EConsoleColor::Reset);
		O3DLIBRARY_API static void WriteLine(const Object& _obj, const EConsoleColor& _color = EConsoleColor::Reset);
#pragma endregion

	};
}
