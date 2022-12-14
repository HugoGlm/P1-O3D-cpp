#pragma once
#include <vector>

template<typename Key, typename Value>
struct Hash
{
	Key key;
	Value value;
};

template<typename Key, typename Value>
class Map
{
#pragma region f/p
private:
	std::vector<Hash> map = std::vector<Hash>();
#pragma endregion
#pragma region constructor
public:
	Map() = default;
	Map(const std::initializer_list<Hash> _map);
	~Map();
#pragma endregion
#pragma region methods
public:
	void Add(const Key& _key, const Value& _value);
	void Remove(const Key& _key);
	bool Contains(const Key& _key);
#pragma endregion
};

#pragma region constructor
template<typename Key, typename Value>
Map<Key, Value>::Map(const std::initializer_list<Hash> _map)
{
	Key _newKey = Hash<Key>(_key);
	Hash<Key, Value> _pair = new Hash<Key, Value>();

}
template<typename Key, typename Value>
Map<Key, Value>::~Map()
{
	delete map;
	map = nullptr;
}
#pragma endregion

#pragma region methods
template<typename Key, typename Value>
void Map<Key, Value>::Add(const Key& _key, const Value& _value)
{
	
}
template<typename Key, typename Value>
void Map<Key, Value>::Remove(const Key& _key)
{
	for (size_t i = 0; i < map.size(); i++)
		if (map[i].key == _key)
			map.erase();
}
template<typename Key, typename Value>
bool Map<Key, Value>::Contains(const Key& _key)
{
	for (size_t i = 0; i < map.size(); i++)
		if (map[i].key == _key)
			return true;
	return false;
}
#pragma endregion

