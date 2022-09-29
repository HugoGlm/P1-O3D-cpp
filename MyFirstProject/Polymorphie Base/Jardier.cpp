#include <iostream>
#include <string>
using namespace std;

int cursor[2];
const int fieldSize = 5;
char garden[fieldSize][fieldSize] =
									{
										{'A', 'X', 'A', 'X', 'A'},
										{'A', 'A', 'X', 'A', 'X'},
										{'X', 'A', 'X', 'A', 'A'},
										{'X', 'A', 'A', 'A', 'X'},
										{'A', 'X', 'A', 'X', 'A'}
									};
#pragma region Proto
void CutTree();
void PlantTree();
void Gardener();
void SetGarden();
#pragma endregion


void SetGarden()
{
	for (int y = 0; y < fieldSize; y++)
	{
		string _tmpLine;
		for (int x = 0; x < fieldSize; x++)
		{
			_tmpLine += garden[y][x];
		}
		cout << _tmpLine << endl;
	}
}
void Gardener()
{
    cout << "Move with z, q, s, d)" << endl;
    char _input;
    bool _isValid = false;
    while (!_isValid)
    {
        cin >> _input;
        _isValid = _input == 's' ||
            _input == 'z' ||
            _input == 'q' ||
            _input == 'd';
    }
    bool _left = _input == 'q',
        _right = _input == 'd',
        _up = _input == 'z',
        _down = _input == 's';
    if (_left)
    {
        cursor[0]--;
        cursor[0] = cursor[0] < 0 ? 0 : cursor[0];
    }
    else if (_right)
    {
        cursor[0]++;
        cursor[0] = cursor[0] > fieldSize - 1 ? fieldSize - 1 : cursor[0];
    }
    else if (_up)
    {
        cursor[1]--;
        cursor[1] = cursor[1] < 0 ? 0 : cursor[1];
    }
    else if (_down)
    {
        cursor[1]++;
        cursor[1] = cursor[1] > fieldSize - 1 ? fieldSize - 1 : cursor[1];
    }
}
void CutTree()
{

}
void PlantTree()
{

}
int main()
{
	SetGarden();
    Gardener();
}