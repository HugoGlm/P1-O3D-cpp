#include <iostream>

template<typename T>
struct IsPointer { enum { Value = false }; };

template<typename T>
struct IsPointer<T*> { enum { Value = true }; };

template<typename T>
struct IsPointer<const T> { enum { Value = IsPointer<T>::Value}; };

template<typename T>
struct RemoveConst { enum { Value = false }; };

template<typename T>
struct RemoveConst<T> { enum { Value = true }; };



int main()
{
   /* std::cout << IsPointer<int>::Value << std::endl;
    std::cout << IsPointer<int*>::Value << std::endl;
    std::cout << IsPointer<const int*>::Value << std::endl;
    std::cout << IsPointer<const int>::Value << std::endl;*/

    std::cout << RemoveConst<int>::Value;
    std::cout << RemoveConst<const int>::Value;
}