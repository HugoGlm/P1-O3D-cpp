#pragma region include
#include <iostream>
#include <string>

using namespace std;
#pragma endregion

#pragma region Proto
int* intArray = nullptr;
int sizeArray = 0;
void clear();
void InitArray(int& _size);
void InsertValue();
void ReadArray();
#pragma endregion

void clear()
{
    delete[] intArray;
}
void InitArray(int& _size)
{
    cout << "set array size : " << endl;
    _size = 0;
    cin >> _size;
    _size = _size <= 0 ? 1 : _size;
    intArray = new int[_size];
    cout << "new int* array size : " << _size << endl;
}
void InsertValue()
{
    for (size_t i = 0; i < sizeArray; i++)
    {
        int _input;
        cout << "Set value : ";
        cin >> _input;
        cout << "new value " << _input << " at index : " << i << endl;
        intArray[i] = _input;
    }
}
void ReadArray()
{
    for (size_t i = 0; i < sizeArray; i++)
        cout << intArray[i] << endl;
}
int main()
{
    InitArray(sizeArray);
    InsertValue();
    ReadArray();
    clear();
}