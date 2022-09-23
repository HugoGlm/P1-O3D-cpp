#include <iostream>
using namespace std;

int a, 
    b, 
    c;
/*
int a = 15, 
    b = 15, 
    c = 10;

void TernaireTest()             //int IfTest()
{                               //{
    a = b > c ? 10 : 5;         //if (b > c)
    cout << a;                  //  return a = 10;
}                               //return a = 5; 
                                //}
                                */
int main()
{
    //TernaireTest();
    bool _isAlien = false;
    bool _isValid = ((b > c) || c == 5 && c * 2 == 10);
    a = _isValid ? 10 : 5;
    int _life = _isAlien ? 1000 : 100;
    bool _isDead = false;
    _isDead = _life <= 0;
}