#pragma once
#include "Object.h"
#include "KeyValuePair.h"
#include "Exception.h"
#include "Boolean.h"

namespace Core
{
	namespace Collection
	{
		template<typename TKey, typename TValue>
		class O3DLIBRARY_API Map : public Object
		{
#pragma region f/p
		private:
			KeyValuePair<TKey, TValue>* tab = new KeyValuePair<TKey, TValue>[50];
			int count = 0;
			int capacity = 50;
		public:
			typedef KeyValuePair<TKey, TValue>* iterator;
			typedef const KeyValuePair<TKey, TValue>* const_iterator;

			iterator begin() { return&tab[0]; }
			const_iterator begin() const { return &tab[0]; }
			iterator end() { return& tab[count]; }
			const_iterator end() const { return &tab[count]; }
#pragma endregion
#pragma region constructor
		public:
			Map() = default;
			Map(const int _capacity)
			{
				capacity = _capacity;
				tab = new KeyValuePair<TKey, TValue>[capacity];
			}
			Map(const std::initializer_list<KeyValuePair<TKey, TValue>>& _list)
			{
				if (_list.size() > capacity)
				{
					capacity = _list.size() * 2;
					tab = new KeyValuePair<TKey, TValue>[capacity];
				}
				for (const KeyValuePair<TKey, TValue>& _pair : _list)
				{
					Add(_pair);
				}
			}
			Map(const Map& _copy)
			{
				tab = _copy.tab;
				count = _copy.count;
				capacity = _copy.capacity;
			}
#pragma endregion
#pragma region methods
		private:
			void Add(const KeyValuePair<TKey, TValue>& _pair)
			{
				if (count + 1 > capacity)
					throw OutOfRangeException("[MAP] => out of range !");
				if (Contains(_pair.Key()))
					throw Exception("[MAP] => Key already exist !");
				const int _hashed = Utils::Hash::GetObjectHashCode(_pair.Key()) % capacity;
				tab[_hashed] = _pair;
				count++;
			}
		public:
			int Count() const
			{
				return count;
			}
			bool Contains(const TKey& _key)
			{
				const int _hashed = Utils::Hash::GetObjectHashCode(_key) % capacity;
				return tab[_hashed].Key() == _key;
			}
			void Add(const TKey& _key, const TValue& _value)
			{
				Add(KeyValuePair<TKey, TValue>(_key, _value));
			}
			void Remove(const TKey& _key)
			{
				if (!Contains(_key))
					throw Exception("[MAP] => Key doesn't exist !");
				const int _hashed = Utils::Hash::GetObjectHashCode(_key) % capacity;
				tab[_hashed] = KeyValuePair<TKey, TValue>();
				count--;
			}
#pragma endregion
#pragma region operator
		public:
			TValue& operator[](const TKey& _key)
			{
				if (!Contains(_key))
					throw Exception("[MAP] => Key doesn't exist !");
				const int _hashed = Utils::Hash::GetObjectHashCode(_key) % capacity;
				return tab[_hashed].Value();
			}
			TValue operator[](const TKey& _key) const
			{
				if (!Contains(_key))
					throw Exception("[MAP] => Key doesn't exist !");
				const int _hashed = Utils::Hash::GetObjectHashCode(_key) % capacity;
				return tab[_hashed].Value();
			}
#pragma endregion

		};
	}
}