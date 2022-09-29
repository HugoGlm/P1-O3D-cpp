#include <iostream>
#include<Windows.h>
#include <string>
using namespace std;

#pragma region Proto
void Init();
void ReadTemple();
void SetCursor();
void CheckEndGame();
int ChooseWeapon(int );
void Inventory();
void Fight();
void SetPlayerEffect();

bool LooseGame();
bool WinGame();

int Ennemy();
#pragma endregion

const int row = 5, column = 5;
char grid[row][column] = {
                                {'S', 'H', 'T', 'E', 'T'},
                                {'T', 'H', 'E', 'T', 'E'},
                                {'H', 'H', 'T', 'H', 'W'},
                                {'H', 'E', 'H', 'H', 'E'},
                                {'H', 'H', 'H', 'T', 'T'},
                            };                           
#pragma region Variable 
int exitRow = 3, exitColumn = 5, currentLocationX = 0, currentLocationY = 0;
int playerLife = 150,
    maxDamage = 20,
    lifeEnnemy = 100,
    maxBonusLife = 40,
    damageEnnemy,
    damageWeapon,
    weapon;
string inventory[5] = {"punch", "stick", "sword", "gun", "lightning"};
int damage[5] = {20, 40, 50, 65, 80};
#pragma endregion
void Init()
{
    for (int y = 0; y < row; y++)
    {
        for (int x = 0; x < column; x++)
        {
            grid[y][x] = '-';
        }
    }
    grid[exitRow][exitColumn] = 'W';
    grid[currentLocationY][currentLocationX] = 'X';
}
void ReadTemple()
{
    string _tmp;
    for (int y = 0; y < row; y++)
    {
        for (int x = 0; x < column; x++)
        {
            _tmp += grid[y][x];
        }
        _tmp += "\n";
    }
    cout << _tmp << endl;
}
void SetCursor()
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
        currentLocationX--;
        currentLocationX = currentLocationX < 0 ? 0 : currentLocationX;
    }
    else if (_right)
    {
        currentLocationX++;
        currentLocationX = currentLocationX > column - 1 ? column - 1 : currentLocationX;
    }
    else if (_up)
    {
        currentLocationY--;
        currentLocationY = currentLocationY < 0 ? 0 : currentLocationY;
    }
    else if (_down)
    {
        currentLocationY++;
        currentLocationY = currentLocationY > row - 1 ? row - 1 : currentLocationY;
    }
    if (grid[currentLocationY][currentLocationX] != 'W');
        grid[currentLocationY][currentLocationX] = 'X';
    cout << "Cursor location is at : " << currentLocationX << "," << currentLocationY << endl;
}
bool LooseGame()
{
    return playerLife == 0;
}
bool WinGame()
{
    return playerLife > 0 && (currentLocationX == exitColumn && currentLocationY == exitRow);
}
void CheckEndGame()
{
    if (LooseGame())
        cout << "You Loose\n";
    else if (WinGame())
        cout << "You Win\n";
}
int ChooseWeapon(int _input)
{
    if (_input == '1')
        damageWeapon = damage[0];
    else if (_input == '2')
        damageWeapon = damage[1];
    else if (_input == '3')
        damageWeapon = damage[2];
    else if (_input == '4')
        damageWeapon = damage[3];
    else if (_input == '5')
        damageWeapon = damage[4];
    cout << damageWeapon << endl;
    cout << damage[0];
    return damageWeapon;
}
void Inventory()
{
    cout << "1 - " << inventory[0] << ", with " << damage[0] << " pts of damage." << endl
         << "2 - " << inventory[1] << ", with " << damage[1] << " pts of damage." << endl
         << "3 - " << inventory[2] << ", with " << damage[2] << " pts of damage." << endl
         << "4 - " << inventory[3] << ", with " << damage[3] << " pts of damage." << endl
         << "5 - " << inventory[4] << ", with " << damage[4] << " pts of damage." << endl;
    cin >> weapon;
    ChooseWeapon(weapon);
}
int Ennemy()
{
    srand((unsigned int)time(NULL));
    damageEnnemy = rand() % (30 - 20 + 1) + 20;
    return damageEnnemy;
}
void Fight()
{
    cout << "Choose weapon in your inventory : \n";
    Ennemy();
    Inventory();
    lifeEnnemy = lifeEnnemy - damageWeapon;
    playerLife = playerLife - damageEnnemy;
    cout << "Damage of the ennemy : " << damageEnnemy << endl;
    cout << "vie du joueur : " << playerLife << endl;
    cout << "vie ennemie  : " << lifeEnnemy << endl;
    if (lifeEnnemy >= 0 && playerLife >= 0)
        Fight();
}
void SetPlayerEffect()
{
    //bool _damage = grid[currentLocationY][currentLocationX];
    //playerLife += _damage ? -maxDamage : maxBonusLife;

    if (grid[row][column] == 'E')
        Fight();
    else if (grid[row][column] == 'T')
        playerLife = playerLife - maxDamage;
    else if (grid[row][column] == 'H')
        playerLife = playerLife + maxBonusLife;

    playerLife = playerLife < 0 ? 0 :
        playerLife > 150 ? 150 :
        playerLife;

    cout << "Player life is : " << playerLife << " PV " << endl;
}
int main()
{
    Init();
    while (true)
    {
        ReadTemple();
        SetPlayerEffect();
        CheckEndGame();
        SetCursor();
    }
}