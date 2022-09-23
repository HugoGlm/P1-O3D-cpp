#include <iostream>
using namespace std;

int a = 10;
int taba[5] = {10, 5, 4, 30, 9};
float tabb[2];

// tableau de taille 5
//array size 5
//array length 5 (longueur)
//0, 1, 2, 3, 4

int main()
{
	//tabb[0] = 12.45f;
	//tabb[1] = 42.45f;
	//cout << tabb[0] << endl;
	//cout << tabb[1] << endl;
	//return 0;
	//cout << taba[0] << endl; // = 10
	//cout << taba[1] << endl; // = 5
	//cout << taba[2] << endl; // = 4
	//cout << taba[3] << endl; // = 30
	//cout << taba[4] << endl; // = 9
	//cout << taba[5] << endl; //crash //index out of range < 0 > size ()
	int _exemple[10];
	for (int i = 0; i < 10; i++)
	{
		_exemple[i] = 100 * i;
		cout << _exemple[i] << endl;
		//do something 
	}
	//boucle
	int b = 45;
	bool _canRun = true;
	for (int i = 0, j = b; i < 100; i++, j+=10)
	{
		cout << "i : " << i << endl;
		cout << "j : " << j << endl;
	}
}