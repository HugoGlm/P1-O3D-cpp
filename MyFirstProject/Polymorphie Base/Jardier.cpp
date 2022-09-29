#include <iostream>
#include<Windows.h>
#include <string>
using namespace std;

const HANDLE _hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

const int gardenSize = 3;
int garden[gardenSize][gardenSize];
int currentX = 0, currentY = 0;

#pragma region Proto
void InitGarden();
void ReadGarden(int _garden[gardenSize][gardenSize]);
void MovePlayer();
void SetCursor();
string GetCursorLocation();
#pragma endregion

string GetCursorLocation()
{
    return "Current location is at : (y = " + to_string(currentY) + ", x = " + to_string(currentX) + ")";
}
void SetCursor()
{
    char _input;
    bool _isValidInput = false;
    while (!_isValidInput)
    {
        cin >> _input;
        _isValidInput = _input == 'z' || _input == 's' || _input == 'd' || _input == 'q';
    }
    if (_input == 'q')
    {
        currentX--;
        currentX = currentX < 0 ? 0 : currentX;
    }
    else if (_input == 'd')
    {
        currentX++;
        currentX = currentX > gardenSize - 1 ? gardenSize - 1 : currentX;
    }
    else if (_input == 'z')
    {
        currentY--;
        currentY = currentY < 0 ? 0 : currentY;
    }
    else if (_input == 's')
    {
        currentY++;
        currentY = currentY > gardenSize - 1 ? gardenSize - 1 : currentY;
    }
    cout << GetCursorLocation() << endl;
}
void MovePlayer()
{
    char _result = garden[currentY][currentX];
    garden[currentY][currentX] = _result == 1 ? 0 : 1;
}
void InitGarden()
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < gardenSize; i++)
    {
        for (int j = 0; j < gardenSize; j++)
        {
            garden[j][i] = rand() % 2;
        }
    }
}
void ReadGarden(int _garden[gardenSize][gardenSize])
{
    string _tmp;
    for (int y = 0; y < gardenSize; y++)
    {
        for (int x = 0; x < gardenSize; x++)
        {
            _tmp += _garden[y][x] == 1 ? " A " : " C ";
        }
        _tmp += "\n";
    }
    cout << _tmp << endl;
}
int main()
{
    InitGarden();
    while (true)
    {
        ReadGarden(garden);
        SetCursor();
        MovePlayer();
    }
}