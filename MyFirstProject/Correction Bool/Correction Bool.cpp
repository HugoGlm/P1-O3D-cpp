#include <iostream>
using namespace std;

#pragma region Game settings
int guessNumber = 10,
    minGuess = 10,
    maxGuess = 25,
    gameAttempt = 0,
    gameAttemptMax = 2;
bool useLimitGame = false;
#pragma endregion
/// <summary>
/// Set guess number between min and max
/// </summary>
/// <param name="_min">min guess number clamp</param>
/// <param name="_max">max guess number clamp</param>
void SetGuessNumber(int _min, int _max)
{
    cout << "Set number between " << _min << " and " << _max << " : ";
    cin >> guessNumber;
    if (guessNumber > _max)
        guessNumber = _max;
    else if (guessNumber < _min)
        guessNumber = _min;
    system("CLS");
}
void GuessGame()
{
    cout << "Guess a number between " << minGuess << " and " << maxGuess << "\n";
    int _guess = 0;
    cin >> _guess;
    cout << "Your input is : " << _guess << "\n";
    //gameAttempt = gameAttempt + 2;
    // gameAttempt +=10; // +10
    //gameAttempt--; //-1
    gameAttempt++; //+1 
    if (useLimitGame)
    {
        if (gameAttempt >= gameAttemptMax)
        {
            cout << "You Lose ! No more try! " << "\n";
            gameAttempt = 0;
            SetGuessNumber(minGuess, maxGuess);
            GuessGame();
        }
    }
    if (_guess == guessNumber)
    {
        cout << "You win ! Guess number was " << _guess << "\n";
        cout << gameAttempt << " Attempt ! " << "\n";
        //game loop
        SetGuessNumber(minGuess, maxGuess);
        GuessGame();
    }
    else if (_guess > guessNumber)
    {
        cout << "You Lose ! You guess is too hight ! " << "\n";
        //game loop
        GuessGame();
    }
    else
    {
        cout << "You Lose ! You guess is too low ! " << "\n";
        //game loop
        GuessGame();
    }
}
int main()
{
    SetGuessNumber(minGuess, maxGuess);
    GuessGame();
}