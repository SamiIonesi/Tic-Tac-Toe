#include <iostream>

using namespace std;

void printArr(char *arr, int length)
{
    for(int i = 0; i < length; i++)
    {
        if(i == 3 || i == 6)
            cout << endl;
        cout << arr[i] << "  ";
    }

    cout << endl;
}

bool check(char *arr, int lenght, char symbol)
{
    if(arr[0] == symbol && arr[1] == symbol && arr[2] == symbol)
        return true;
    if(arr[3] == symbol && arr[4] == symbol && arr[5] == symbol)
        return true;
    if(arr[6] == symbol && arr[7] == symbol && arr[8] == symbol)
        return true;
    if(arr[0] == symbol && arr[3] == symbol && arr[6] == symbol)
        return true;
    if(arr[1] == symbol && arr[4] == symbol && arr[7] == symbol)
        return true;
    if(arr[2] == symbol && arr[5] == symbol && arr[8] == symbol)
        return true;
    if(arr[0] == symbol && arr[4] == symbol && arr[8] == symbol)
        return true;
    if(arr[2] == symbol && arr[4] == symbol && arr[6] == symbol)
        return true;

    return false;
}

bool turn(char *arr, int length, bool checkForWinner, int player, int playerNumber, char symbol)
{
    cout << endl << "Player " << playerNumber << ": " << endl;
    cin >> player;

    while(arr[player] == 'O' || arr[player] == 'X')
    {
        cout << endl << "Box " << player << " is already fill. Try again: " << endl;
        cin >> player;
    }

    arr[player] = symbol;
    checkForWinner = check(arr, length, symbol);

    printArr(arr, length);

    if(checkForWinner)
    {
        cout << "Player " << playerNumber << " won the game." << endl;
        return true;
    }
    return false;
}

void game(char *arr, int length)
{
    int player1;
    int player2;
    bool checkForWinner = false;
    bool playAgain = true;
    int play;

    while(playAgain)
    {
        printArr(arr, length);

        while(!checkForWinner)
        {
            checkForWinner = turn(arr, length, checkForWinner, player1, 1, 'X');

            if(checkForWinner)
                break;

            checkForWinner = turn(arr, length, checkForWinner, player2, 2, 'O');
        }

        cout << endl << "Do you want to play again? " << endl;
        cout << "Type 1 for 'yes' or 2 for 'no'" << endl;
        cin >> play;

        if(play == 2)
        {
            playAgain = false;
            cout << "Game over. Goodbye!" << endl;
        }
        else if(play == 1)
        {
            checkForWinner = false;

            for(int i = 0; i < length; i++)
            {
                arr[i] = 48 + i;
            }
        }
        else
        {
            cout << "Incorrect number. try again: " << endl;
            cin >> play;
        }
    }
}

int main()
{

    char arr[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
    int length = sizeof(arr) / sizeof(arr[0]);

    bool chechForWinner;

    cout << "Welcome to the Tic-Tac-Toe game!" << endl;

    //printArr(arr, length);

    game(arr, length);

    return 0;
}