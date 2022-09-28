#include <iostream>
#include<Windows.h>
#include <string>
using namespace std;

const int row = 5, column = 5;
char grid[row][column];
char content[row][column] =
                            {
                                {'S', 'H', 'T', 'E', 'T'},
                                {'T', 'H', 'E', 'T', 'E'},
                                {'H', 'H', 'T', 'H', 'W'},
                                {'H', 'E', 'H', 'H', 'E'},
                                {'H', 'H', 'H', 'T', 'T'},
                            };
#pragma region Variable 
int exitRow = 3, exitColumn = 5, currentLocationX = 0, currentLocationY = 0;
int playerLife = 100,
    maxDamage = 20,
    lifeEnnemy = 100,
    maxBonusLife = 10,
    damageEnnemy,
    damageWeapon,
    damage1,
    damage2,
    damage3,
    damage4,
    damage5,
    weapon;
string inventory[5] = {"punch", "stick", "sword", "gun", "lightning"};
int damage[5] = { 20, 40, 50, 65, 80 };
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
    grid[exitRow][exitColumn] = 'E';
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
void SetPlayerEffect()
{
    bool _damage = content[currentLocationY][currentLocationX];
    playerLife += _damage ? -maxDamage : maxBonusLife;

    playerLife = playerLife < 0 ? 0 :
        playerLife > 100 ? 100 :
        playerLife;

    cout << "Player life is : " << playerLife << " PV " << endl;
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
int ChooseWeapon()
{
    srand((unsigned int)time(NULL));
    if (weapon == '1')
        return damageWeapon = damage[0];
    else if (weapon == '2')
        return damageWeapon = damage[1];
    else if (weapon == '3')
        return damageWeapon = damage[2];
    else if (weapon == '4')
        return damageWeapon = damage[3];
    else if (weapon == '5')
        return damageWeapon = damage[4];
}
void Inventory()
{
    cout << "1 - " << inventory[0] << ", with " << damage[0] << " pts of damage." << endl
         << "2 - " << inventory[1] << ", with " << damage[1] << " pts of damage." << endl
         << "3 - " << inventory[2] << ", with " << damage[2] << " pts of damage." << endl
         << "4 - " << inventory[3] << ", with " << damage[3] << " pts of damage." << endl
         << "5 - " << inventory[4] << ", with " << damage[4] << " pts of damage." << endl;
    cin >> weapon;
    ChooseWeapon();
}
int Ennemy()
{
    srand((unsigned int)time(NULL));
    damageEnnemy = rand() % 30;
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
int main()
{

    Fight();
   /* Init();
    while (true)
    {
        ReadTemple();
        SetPlayerEffect();
        CheckEndGame();
        SetCursor();
    }*/
}


