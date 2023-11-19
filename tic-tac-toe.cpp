#include <iostream>
#include <vector>

// Function prototypes
void initializeBoard(std::vector<std::vector<char>>& board);
void displayBoard(const std::vector<std::vector<char>>& board);
bool makeMove(std::vector<std::vector<char>>& board, char currentPlayer, int row, int col);
bool checkForWin(const std::vector<std::vector<char>>& board, char currentPlayer);
bool checkForDraw(const std::vector<std::vector<char>>& board);
char switchPlayer(char currentPlayer);

int main() {
    // Initialize the Tic-Tac-Toe board
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));

    char currentPlayer = 'X';
    int row, col;
    bool gameWon = false;
    bool gameDraw = false;

    std::cout << "Welcome to Tic-Tac-Toe!\n";

    do {
        // Display the current state of the board
        displayBoard(board);

        // Player input
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        // Make the move and update the board
        if (makeMove(board, currentPlayer, row, col)) {
            // Check for a win
            gameWon = checkForWin(board, currentPlayer);
            if (gameWon) {
                displayBoard(board);
                std::cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            // Check for a draw
            gameDraw = checkForDraw(board);
            if (gameDraw) {
                displayBoard(board);
                std::cout << "It's a draw!\n";
                break;
            }

            // Switch players for the next turn
            currentPlayer = switchPlayer(currentPlayer);
        } else {
            std::cout << "Invalid move. Try again.\n";
        }

    } while (!gameWon && !gameDraw);

    std::cout << "Thanks for playing Tic-Tac-Toe!\n";

    return 0;
}

void initializeBoard(std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "Current Board:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j];
            if (j < 2) {
                std::cout << " | ";
            }
        }
        std::cout << "\n";
        if (i < 2) {
            std::cout << "---------\n";
        }
    }
}

bool makeMove(std::vector<std::vector<char>>& board, char currentPlayer, int row, int col) {
    // Check if the chosen cell is empty
    if (board[row - 1][col - 1] == ' ') {
        board[row - 1][col - 1] = currentPlayer;
        return true;
    } else {
        return false;
    }
}

bool checkForWin(const std::vector<std::vector<char>>& board, char currentPlayer) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }

    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }

    return false;
}

bool checkForDraw(const std::vector<std::vector<char>>& board) {
    // Check if all cells are filled
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; // There is an empty cell, game is not a draw
            }
        }
    }
    return true; // All cells are filled, game is a draw
}

char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}
