#include <iostream>
#include <string>
#include <vector>
using namespace std;

//AddFirst
//AddLast
//Clear
//AddAfter
//AddBefore
//Remove
//RemoveFirst
//RemoveLast
//Contains

class Node
{
public:
    int data;
    Node* next = nullptr;
    Node* last = nullptr;
};
int main()
{
    vector<int> tab = vector <int>();
    tab.push_back(5);
    tab.emplace_back();
    tab.size();
    tab.erase(tab.end() + 5);
    tab[0] = 5;
    cout << tab[0];
}