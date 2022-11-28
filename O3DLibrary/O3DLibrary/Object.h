#pragma once
#include "O3DLibrary.h"
#include <iostream>
#include <map>
#include <vector>

#pragma warning(disable : 4251)

namespace Core
{
	namespace PrimitiveType
	{
		class FString;
		class Boolean;
	}
	enum class BindingFlags;
	class FieldInfo;
	class O3DLIBRARY_API Object
	{
#pragma region f/p
	private:
		std::map<const char*, FieldInfo*> fields = std::map<const char*, FieldInfo*>();
#pragma endregion

#pragma region constructor
	public:
		Object() = default;
		virtual ~Object() = default;
#pragma endregion
#pragma region methods
	protected: 
		int RegisterField(const char* _name, Object* _obj, int _mask);
	public:
		virtual Core::PrimitiveType::Boolean Equals(const Object* _obj) const;
		virtual Core::PrimitiveType::FString ToString() const;
		std::vector<FieldInfo*> GetFields() const;
		std::vector<FieldInfo*> GetFields(BindingFlags _flags) const;
		FieldInfo* GetField(const char* _name);
		template<typename T>
		void SetValue(Object* obj);
		template<typename T>
		void SetFieldValue(const char* _name, T* _value);
#pragma endregion
#pragma region operator
	public:
		virtual Object& operator=(const Object* obj);
#pragma endregion
	};
	typedef Object* object;

	template<typename T>
	inline void Object::SetValue(Object* obj)
	{
		*((T*)this) = obj;
	}
	template<typename T>
	void Object::SetFieldValue(const char* _name, T* _value)
	{
		if (!fields.contains(_name))
			return;
		*fields[_name] = _value;
	}
}
