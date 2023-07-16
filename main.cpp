#include "main/game.h"

void drawGameOver()
{
    system("cls");
    cout << "=========================" << endl;
    cout << "        GAME OVER        " << endl;
    cout << "=========================" << endl;
}

bool gameover()
{
    // Check for a win condition (3 in a row horizontally, vertically, or diagonally)
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            drawGameOver();
            cout << "Player " << (turn ? "1 (X)" : "2 (O)") << " wins!" << endl;
            return true;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            drawGameOver();
            cout << "Player " << (turn ? "1 (X)" : "2 (O)") << " wins!" << endl;
            return true;
        }
    }

    // Check for a diagonal win
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        drawGameOver();
        cout << "Player " << (turn ? "1 (X)" : "2 (O)") << " wins!" << endl;
        return true;
    }

    // Check for a draw condition
    bool draw = true;
    char arr[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int n = sizeof(arr) / sizeof(*arr);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (std::find(arr, arr + n, board[i][j]) != arr + n) {
                draw = false;
                break;
            }
        }
        if (!draw) {
            break;
        }
    }

    if (draw) {
        drawGameOver();
        cout << "It's a draw!" << endl;
        return true;
    }

    return false;
}



void gameboard()
{

    if(turn)
        cout << "PLAYER - 1 [X] \n";
    else
        cout << "PLAYER - 2 [O] \n";

    cout<<"     |     |     \n";
    cout<<"  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<" \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<" \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<" \n";
    cout<<"     |     |     \n";

}

bool checkValidField(int y, int x)
{

    bool valid;



    char arr[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char target = board[y][x];
    int n = sizeof(arr) / sizeof(*arr);

    bool exists = std::find(arr, arr + n, target) != arr + n;
    if (exists) {
        valid = true;
    } else {
        valid = false;
    }


    return valid;
}

void switchTurn()
{
    if(turn)
        turn = false;
    else
        turn = true;
}

void gameloop()
{
    char coice;
    char boardPrint;
    while(game)
    {
        cout << "$ ";
        cin >> coice;

        if(turn)
            boardPrint = 'X';
        else
            boardPrint = 'O';
        switch (coice)
        {
            case '1':
                if (!checkValidField(0, 0)) break;
                board[0][0] = boardPrint;
                switchTurn();
                break;
            case '2':
                if (!checkValidField(0, 1)) break;
                board[0][1] = boardPrint;
                switchTurn();
                break;
            case '3':
                if (!checkValidField(0, 2)) break;
                board[0][2] = boardPrint;
                switchTurn();
                break;
            case '4':
                if (!checkValidField(1, 0)) break;
                board[1][0] = boardPrint;
                switchTurn();
                break;
            case '5':
                if (!checkValidField(1, 1)) break;
                board[1][1] = boardPrint;
                switchTurn();
                break;
            case '6':
                if (!checkValidField(1, 2)) break;
                board[1][2] = boardPrint;
                switchTurn();
                break;
            case '7':
                if (!checkValidField(2, 0)) break;
                board[2][0] = boardPrint;
                switchTurn();
                break;
            case '8':
                if (!checkValidField(2, 1)) break;
                board[2][1] = boardPrint;
                switchTurn();
                break;
            case '9':
                if (!checkValidField(2, 2)) break;
                board[2][2] = boardPrint;
                switchTurn();
                break;
            case 'q':
                game = false;
            case 'n':
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        board[i][j] = clearboard[i][j];
                    }
                }
                turn = true;

            default:
                break;
        }

        if(!gameover())
        {
            system("cls");
            gameboard();
        }
        else
        {

        }
    }
}

int main()
{
    system("title TICTACTOE");
    system("color 74");
    gameboard();
    gameloop();

    return 0;
}