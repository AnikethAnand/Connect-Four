#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

// Prototypes
void InitialiseBoard(int board[MAX_SIZE][MAX_SIZE], int size, char *values);
void PrintGrid(int board[MAX_SIZE][MAX_SIZE], int size);
int MakeMove(int board[MAX_SIZE][MAX_SIZE], int size, char side, int move, int player);
int FourInARow(int board[MAX_SIZE][MAX_SIZE], int size, int row, int col);

int CheckWinner(int board[MAX_SIZE][MAX_SIZE], int size) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            int result = FourInARow(board, size, r, c);
            if (result != 0) return result;
        }
    }
    return 0;
}

int main() {
    int board[MAX_SIZE][MAX_SIZE];
    int size = 7; 
    int currentPlayer = 1;
    
    InitialiseBoard(board, size, NULL);

    while (true) {
        PrintGrid(board, size);

        char side;
        int move;
        int valid = 0;

        while (!valid) {
            printf("Player %d - Enter side (T/B/L/R): ", currentPlayer);
            if (scanf(" %c", &side) != 1) return 0;
            printf("Player %d - Enter index (0-%d): ", currentPlayer, size - 1);
            if (scanf(" %d", &move) != 1) return 0;

            valid = MakeMove(board, size, side, move, currentPlayer);
        }

        if (CheckWinner(board, size) != 0) {
            PrintGrid(board, size);
            printf("Player %d wins!\n", currentPlayer);
            break;
        }
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
    return 0;
}