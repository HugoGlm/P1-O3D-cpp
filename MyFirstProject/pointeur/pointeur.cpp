#include <iostream>
using namespace std;

int* ptrA = nullptr;
int* ptrB = nullptr;
int a = 5, b = 15;

void SwapAToB()
{
    int _tmp = a;
    cout << "a : " << a << endl;
    cout << "b : " << b << endl;
    a = b;
    cout << "a : " << a << endl;
    b = _tmp;
    cout << "b : " << b << endl;
}
void SwapAB(int* _a, int* _b) // swap adresse de A a B
{
    cout << "--- Swap des adresse ---\n";
    _a = &a;
    _b = &b;
    int* _tmp = _a;
    cout << "a : " << _a << endl; // *_a pour la valeur et _a pour l'adresse
    cout << "b : " << _b << endl; // *_b pour la valeur et _b pour l'adresse

    _a = _b;
    _b = _tmp;
    cout << "a : " << _a << endl; // *_a pour la valeur et _a pour l'adresse
    cout << "b : " << _b << endl; // *_b pour la valeur et _b pour l'adresse
}
void Location() // localiser une nouvelle adresse et la libere apres 
{
    cout << "--- adresse ---\n";
    int* _integer = new int(5);
    cout << _integer << endl;
    cout << *_integer << endl;
    *_integer = 100;
    cout << *_integer << endl;
    delete _integer;
}
int main()
{
    SwapAB(ptrA, ptrB);
    Location();
}