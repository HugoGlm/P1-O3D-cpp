#include <iostream>
#include <string>

int a = 5;

int main()
{
	char* _chaine = new char[3];
	_chaine[0] = 'S';
	_chaine[1] = 'T';
	_chaine[2] = '\0';
	std::cout << _chaine << std::endl;
	delete[] _chaine;
    int* _tabInt = new int[a];
	for (int i = 0; i < a; i++)
	{
		_tabInt[i] = i;
		std::cout << _tabInt[i] << std::endl;
	} 
	std::cout << _tabInt << std::endl;
	std::cout << &_tabInt[0] << std::endl;
	std::cout << &_tabInt[1] << std::endl;
	std::cout << &_tabInt[2] << std::endl;
	std::cout << &_tabInt[3] << std::endl;
	std::cout << &_tabInt[4] << std::endl;
	int* _other = new int[a];
	std::cout << _other << std::endl;
	delete[] _tabInt, _other;
}