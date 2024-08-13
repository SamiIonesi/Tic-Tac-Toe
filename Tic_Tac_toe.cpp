#include <iostream>
#include <limits>

using namespace std;


class TicTacToe
{
private:
    int length;
    char gameTable[];

public:

    int getLength() { return this->length; }
    char* getGameTable() {return this->gameTable; }

    void fillGameTable(char *arr, int length)
    {
        for(int i = 0; i < length; i++)
        {
            arr[i] = 48 + i;
        }
    }

    TicTacToe()
    {
        this->length = 9;
        fillGameTable(gameTable, length);
    }

    void printGameTable(char *arr, int length)
    {
        cout << endl;

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

        printGameTable(arr, length);

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
            cout << "Welcome to the Tic-Tac-Toe game!" << endl;
            printGameTable(arr, length);

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

                fillGameTable(arr, length);
            }
            else
            {
                //this one is not working properly
                while(play != 1 && play != 2)
                {
                    cout << "Incorrect number. Try again: " << endl;

                    cin >> play;

                    cin.clear();

                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        }
    }

};


int main()
{

    TicTacToe ttt;

    ttt.game(ttt.getGameTable(), ttt.getLength());

    return 0;
}