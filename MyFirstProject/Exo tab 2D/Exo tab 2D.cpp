#include <iostream>
#include <string>
using namespace std;

const int sizeTab = 5;
string nameTab[sizeTab][2] = {
								{"Lebron", "James"},
								{"Jean", "Raoul"},
								{"Jean", "Pierre"},
								{"Jean", "Louis"},
								{"Jean", "neymar"}
};

int main()
{
	for (int i = 0; i < sizeTab; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << nameTab[i][j] << " ";
		}
		cout << endl;
	}
}