#include <iostream>
#include <string>
using namespace std;

int tabSize;

#pragma region Proto
void ChooseSize();
void Sorter();
#pragma endregion

void ChooseSize()
{
	cout << "What size off tab ? \n";
	cin >> tabSize;
}
void Sorter()
{
	int* _chaine = new int[tabSize];
	int _value;
	for (int i = 0; i < tabSize; i++)
	{
		cout << "Set value : ";
		cin >> _value;
		_chaine[i] = _value;
	}
	cout << "--- Sorter ---" << endl;
	for (int i = 0; i < tabSize; i++)
	{
		if (_chaine[i] < _chaine[i - 1])
		{
			cout << _chaine[i] << endl;
			//cout << _chaine[i - 1] << endl;
		}
	}
	for (int i = 0; i < tabSize; i++)
	{
		if (_chaine[i] > _chaine[i - 1])
		{
			cout << _chaine[i] << endl;
			//cout << _chaine[i - 1] << endl;
		}
	}
	delete[] _chaine;
}
int main()
{
	ChooseSize();
	Sorter();
}

