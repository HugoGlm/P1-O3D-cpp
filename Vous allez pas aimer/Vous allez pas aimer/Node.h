#pragma once
#include <iostream>

template<typename T>

class Node
{
#pragma region f/p
private:
	T* Data = nullptr;
	Node* prev = nullptr;
	Node* next = nullptr;
#pragma endregion
#pragma region constructor
public:
	Node() = default;
	Node(const std::string& _data);
	Node(const Node& _copy);
#pragma endregion
#pragma region methods
#pragma endregion
};

template<typename T>
inline Node<T>::Node(const std::string& _data)
{
	data = _data;
}

template<typename T>
inline Node<T>::Node(const Node& _copy)
{
	data = _copy.Data;
}
