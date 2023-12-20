#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int boardSize = 7;

struct Ship {
    int length;
    int hits;
};

struct Player {
    string name;
    int shots;
};

char board[boardSize][boardSize];

int initializeBoard() {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            board[i][j] = ' ';
        }
    }
    board[1][1] = board[1][2] = board[1][3] = 'S';  
    board[3][3] = board[3][4] = 'S';                
    board[5][5] = 'S';                              
}

int printBoard() {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}

bool isValidMove(int row, int col) {
    return row >= 0 && row < boardSize && col >= 0 && col < boardSize && board[row][col] == ' ';
}

bool isGameOver() {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if (board[i][j] == 'S') {
                return false; 
            }
        }
    }
    return true; 
}

int playGame(const string& playerName) {
    initializeBoard();
    int shots = 0;

    while (!isGameOver()) {
        int row, col;
    cout << playerName << ", enter your guess (row and column): ";
    cin >> row >> col;

        if (!isValidMove(row, col)) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        if (board[row][col] == 'S') {
            cout << "Hit!" << endl;
            board[row][col] = 'X';  
        } else {
            cout << "Miss!" << endl;
            board[row][col] = 'O';  
        }
        printBoard();
        shots++;
    }

    cout << "Congratulations, " << playerName << "! You sank all the ships in " << shots << " shots." << endl;
}

int main() {
    srand((time(0)));
    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;

    playGame(playerName);

    return 0;
}
