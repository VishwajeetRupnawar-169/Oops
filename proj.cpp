#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) {
                cout << "|";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "---+---+---" << endl;
        }
    }
    cout<<"\n\n\n";
}


char checkGameOver(const vector<vector<char>>& board) {
   
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

  
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return ' ';
            }
        }
    }

    return 'D';  
}


void makeRandomMove(vector<vector<char>>& board) {
    while (true) {
        int row = rand() % 3;
        int col = rand() % 3;
        if (board[row][col] == ' ') {
            board[row][col] = 'O';
            break;
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(0))); 
    vector<vector<char>> board(3, vector<char>(3, ' '));
    bool playerTurn = true;

    cout << "Tic-Tac-Toe Game\n";

    while (true) {
        printBoard(board);

        if (playerTurn) {
            int row, col;
            cout << "Enter your move (row and column): ";
            cin >> row >> col;
            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
                board[row][col] = 'X';
                playerTurn = false;
            } else {
                cout << "Invalid move. Try again.\n";
            }
        } else {
            makeRandomMove(board);
            playerTurn = true;
        }

        char result = checkGameOver(board);
        if (result != ' ') {
            printBoard(board);
            if (result == 'X') {
                cout << "You win!" << endl;
            } else if (result == 'O') {
                cout << "Computer wins!" << endl;
            } else {
                cout << "It's a draw!" << endl;
            }
            break;
        }
    }

    return 0;
}
