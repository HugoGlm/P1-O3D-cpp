#pragma once
#include "Object.h"
#include "Uri.h"

namespace Core
{
	namespace Net
	{
		class O3DLIBRARY_API WebClient : public Object
		{
#pragma region f/p
		private:
			Uri uri = Uri();
#pragma endregion
#pragma region constructor
		public:
			WebClient() = default;
			WebClient(const Uri& _uri);
			WebClient(const WebClient& _copy);
#pragma endregion
#pragma region methods
		public:
			void DownloadFile(const PrimitiveType::FString& _pathFile);
#pragma endregion

		};
	}
}
