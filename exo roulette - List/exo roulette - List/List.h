#pragma once
#include <initializer_list>
#include <stdexcept>

template<typename T>
class List
{
#pragma region f/p
private:
	int count = 0;
	T* tab = nullptr;
#pragma endregion
#pragma region constructor
public:
	List();
	List(std::initializer_list<T> _tab);
	List(const List& _copy);
	~List();
#pragma endregion
#pragma region methods
private:
	int FindOf(const T& _item);
public:
	void Add(const T& _item);
	void Clear();
	int Count();
	void Remove(const T& _item);
	void RemoveAt(const int& _index);
	void RemoveAll(const T& _item);
	bool Contains(const T& _item);
#pragma endregion
#pragma region operator
public:
	T& operator[](int _index);
#pragma endregion
};

#pragma region constructor
template<typename T>
List<T>::List()
{
	tab = new T[0];
	count = 0;
}
template<typename T>
List<T>::List(std::initializer_list<T> _tab)
{
}
template<typename T>
List<T>::List(const List& _copy)
{
}
template<typename T>
List<T>::~List()
{
	Clear();
}
#pragma endregion
#pragma region methods
template<typename T>
inline int List<T>::FindOf(const T& _item)
{
	for (int i = 0; i < count; i++)
	{
		if (tab[i] == _item)
			return i;
	}
	return -1;
}
template<typename T>
void List<T>::Add(const T& _item)
{
	T* _tmp = tab;
	tab = new T[count + 1];
	for (int i = 0; i < count; i++)
		tab[i] = _tmp[i];
	tab[count] = _item;
	count++;
}
template<typename T>
void List<T>::Clear()
{
	if (count > 0)
		delete[] tab;
	else
		delete tab;
	count = 0;
}
template<typename T>
int List<T>::Count()
{
	return count;
}
template<typename T>
void List<T>::Remove(const T& _item)
{
	const int _index = FindOf(_item);
	if (_index == -1)
		throw std::out_of_range("[list] => cant find item !");
	RemoveAt(_index);
}
template<typename T>
void List<T>::RemoveAt(const int& _index)
{
	T* _tmp = tab;
	tab = new T[count - 1];
	for (int i = 0; i < _index; i++)
		tab[i] = _tmp[i];
	for (size_t i = 0; i < count; i++)
		tab[i - 1] = _tmp[i];
	count--;
}
template<typename T>
void List<T>::RemoveAll(const T& _item)
{
}
template<typename T>
bool List<T>::Contains(const T& _item)
{
	for (int i = 0; i < count; i++)
	{
		if (tab[i] == _item)
			return true;
	}
	return false;
}
#pragma endregion
#pragma region operator
template<typename T>
inline T& List<T>::operator[](int _index)
{
	return tab[_index];
}
#pragma endregion