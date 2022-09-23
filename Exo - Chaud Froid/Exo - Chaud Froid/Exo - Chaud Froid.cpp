#include <iostream>
using namespace std;
#pragma region Parameter
int numberGuess = 0,
    minGuess = 1,
    maxGuess = 100,
    gameAttempt = 0,
    gameAttemptMax = 30;
bool useLimitGame = true;
#pragma endregion
void SetGuessNumber(int _min, int _max)
{
    gameAttempt = 0;
    cout << "Set number between " << _min << " and " << _max << endl;
    cin >> numberGuess;
    if (numberGuess < minGuess || numberGuess > maxGuess)
        SetGuessNumber(minGuess, maxGuess);
    system("CLS");
}
void GuessGame()
{
    cout << "Choose number between " << minGuess << " and " << maxGuess << endl;
    int _number = 0;
    cin >> _number;
    gameAttempt++;
    if (useLimitGame)
    {
        if (gameAttempt >= gameAttemptMax)
        {
            cout << "You lose ! No more try \n";
            SetGuessNumber(minGuess, maxGuess);
            GuessGame();
        }
    }
    if (_number < numberGuess)
    {
        cout << "More !\n";
        GuessGame();
    }
    else if (_number > numberGuess)
    {
        cout << "less !\n";
        GuessGame();
    }
    else if (_number == numberGuess)
    {
        cout << "It's win !\n";
        cout << gameAttempt << " attempt !\n";
        SetGuessNumber(minGuess, maxGuess);
        GuessGame();
    }

}
int main()
{
    SetGuessNumber(minGuess, maxGuess);
    GuessGame();
}