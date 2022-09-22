#include <iostream>
using namespace std;

string firstWordFr = "avion", secondWordFr = "arbre",
       firstWordEn = "plane", secondWordEn = "tree";
string lastInput;
bool isFrenchTranslation = false;

string GetModeWords(bool _frMode)
{
    if (isFrenchTranslation)
    {
        return "words are : " + firstWordEn + ", " + secondWordEn;
    }
    else 
        return "Les mots sont  : " + firstWordFr + ", " + secondWordFr;
}

void InitTranslator(bool _frMode)
{
    cout << GetModeWords(_frMode) << endl;
}

string IsValidWord(string _input)
{
    if (_input == firstWordFr)
        return firstWordEn;
    if (_input == secondWordFr)
        return secondWordEn;
    if (_input == firstWordEn)
        return firstWordFr;
    if (_input == secondWordEn)
        return secondWordFr;
}

string InputMode()
{
    string _input;
    cin >> _input;
    cout << "Word is : " << _input << endl;
    return _input;
}

int main()
{
    InitTranslator(isFrenchTranslation);
    lastInput = InputMode();
    cout << IsValidWord(lastInput) << endl;
    main();
}