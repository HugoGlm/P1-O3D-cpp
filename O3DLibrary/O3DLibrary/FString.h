#pragma once
#include "Object.h"
#include <string>
#include <ostream>
#include <vector>

namespace Core
{
    namespace PrimitiveType
    {
#pragma warning(disable: 4996)

        class Boolean;
        class Integer;

        class FString : public Object
        {
#pragma region f/p
        private:
            const char* value = "";
            int length = 0;
        public:
            static const FString Empty;
#pragma endregion 

#pragma region constructor/destructor
        public:
            O3DLIBRARY_API FString(const char* _value);
            O3DLIBRARY_API FString(const FString& _copy);
            O3DLIBRARY_API FString(std::string::iterator _begin, std::string::iterator _end);
#pragma endregion 

#pragma region methods
        public:
            O3DLIBRARY_API void Append(const char _char);
            O3DLIBRARY_API void Append(const FString& _value);
            O3DLIBRARY_API FString SubString(const int _begin, const int _end) const;
            O3DLIBRARY_API FString SubString(const int _begin) const;
            O3DLIBRARY_API FString Replace(const char _old, const char _new) const;
            O3DLIBRARY_API FString Replace(const FString& _old, const FString& _new) const;
            O3DLIBRARY_API FString Trim() const;
            O3DLIBRARY_API FString ToUpper() const;
            O3DLIBRARY_API FString ToLower() const;
            O3DLIBRARY_API Integer Length() const;
            O3DLIBRARY_API Boolean StartWith(const char _c) const;
            O3DLIBRARY_API Boolean StartWith(const FString& _str) const;
            O3DLIBRARY_API Boolean EndWith(const char _c) const;
            O3DLIBRARY_API Boolean EndWith(const FString& _str) const;
            O3DLIBRARY_API Boolean Contains(const FString& _str) const;
            O3DLIBRARY_API Integer LastIndexOf(const char _c) const;
            O3DLIBRARY_API Integer FirstIndexOf(const char _c) const;
            O3DLIBRARY_API Integer Find(const FString& _str) const;
            O3DLIBRARY_API std::wstring ToWString() const;
            O3DLIBRARY_API const char* ToCstr() const;
            O3DLIBRARY_API static Boolean IsNullOrEmpty(const FString& _str);
            O3DLIBRARY_API Boolean Equals(const FString& _other) const;
            template<typename ...Args>
            O3DLIBRARY_API static FString Format(const FString& _str, Args... _args);
#pragma endregion

#pragma region override
        public:
            O3DLIBRARY_API FString ToString() const override;
            O3DLIBRARY_API Boolean Equals(const Object* _obj) const override;
#pragma endregion

#pragma region operator
            O3DLIBRARY_API operator const char* () const;
            O3DLIBRARY_API friend std::ostream& operator<<(std::ostream& _os, const FString& _str);
            O3DLIBRARY_API Boolean operator==(const FString& _other) const;
            O3DLIBRARY_API Boolean operator!=(const FString& _other) const;
            O3DLIBRARY_API FString operator+(const FString& _other) const;
            O3DLIBRARY_API FString& operator+=(const FString& _other);
            O3DLIBRARY_API char operator[](const int _index);
#pragma endregion
        };

#pragma region methods
        template<typename ...Args>
        FString FString::Format(const FString& _str, Args ..._args)
        {
            FString _result = "";
            std::vector<object> _arguments = std::vector<object>();
            //size_t _count = sizeof...(_args); //=> nombre d'arguments dans _args
            (_arguments.push_back(&_args), ...);
            int _index = 0;
            for (int i = 0; i < _str.length; i++)
            {
                if (_str[i] == '{' && _str[i + 1] == '}')
                {
                    _result.Append(_arguments[i]->ToString());
                    _index++, i++;
                }
                else _result.Append(_str[i]);
            }
            return _result;
        }
#pragma endregion
    }
}