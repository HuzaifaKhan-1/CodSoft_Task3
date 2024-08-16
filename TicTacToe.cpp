#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE];
char currentPlayer;

void initializeBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    cout << "Current Board:\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "--+---+--\n";
    }
    cout << endl;
}

bool isMoveValid(int row, int col) {
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ';
}

void playerMove() {
    int row, col;
    while (true) {
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        if (isMoveValid(row - 1, col - 1)) {
            board[row - 1][col - 1] = currentPlayer;
            break;
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }
}

bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}

bool checkDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void displayResult(bool win, bool draw) {
    if (win) {
        cout << "CONGRATS! Player " << currentPlayer << " wins!\n";
    } else if (draw) {
        cout << "The game is a draw!\n";
    } else {
        cout << "The game is ongoing.\n";
    }
}

bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return choice == 'y' || choice == 'Y';
}

int main() {
    do {
        initializeBoard();
        currentPlayer = 'X';
        bool win = false, draw = false;
        while (!win && !draw) {
            displayBoard();
            playerMove();
            win = checkWin();
            draw = checkDraw();
            if (!win && !draw) switchPlayer();
        }
        displayBoard();
        displayResult(win, draw);
    } while (playAgain());

    return 0;
}
