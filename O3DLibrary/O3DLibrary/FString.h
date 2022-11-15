#pragma once
#include "Object.h"
#include <string>
#include <ostream>

namespace Core
{
    namespace PrimitiveType
    {
#pragma warning(disable: 4996)

        class Boolean;

        class FString : public Object
        {
#pragma region f/p
        private:
            const char* value = "";
            int length = 0;
        public:
            static const FString Empty;
#pragma endregion f/p
#pragma region constructor/destructor
        public:
            O3DLIBRARY_API FString(const char* _value);
            O3DLIBRARY_API FString(const FString& _copy);
            O3DLIBRARY_API FString(std::string::iterator _begin, std::string::iterator _end);
#pragma region constructor/destructor
#pragma region methods
        public:
            O3DLIBRARY_API void Append(const char _char);
            O3DLIBRARY_API void Append(const FString& _value);
            O3DLIBRARY_API FString SubString(const int _begin, const int _end);
            O3DLIBRARY_API FString SubString(const int _begin);
            O3DLIBRARY_API FString Replace(const char _old, const char _new) const;
            O3DLIBRARY_API FString Replace(const FString& _old, const FString& _new) const;
            O3DLIBRARY_API FString Trim() const;
            O3DLIBRARY_API FString ToUpper() const;
            O3DLIBRARY_API FString ToLower() const;
            O3DLIBRARY_API int Length() const;
            O3DLIBRARY_API const char* ToCstr() const;
            O3DLIBRARY_API Boolean IsNullOrEmpty(const FString& _str);
#pragma endregion methods
#pragma region override
        public:
            O3DLIBRARY_API FString ToString() const override;
#pragma endregion override
#pragma region operator
            O3DLIBRARY_API operator const char* ();
            O3DLIBRARY_API friend std::ostream& operator<<(std::ostream& _os, const FString& _str);
            O3DLIBRARY_API Boolean operator==(const FString& _other);
            O3DLIBRARY_API Boolean operator!=(const FString& _other);
#pragma endregion operator
        };
    }
}