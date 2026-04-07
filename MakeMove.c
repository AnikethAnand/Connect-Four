#include <stdio.h>
#include <stddef.h>
#define MAX_SIZE 10 

void PopIn(int board[MAX_SIZE][MAX_SIZE], int size, char side, int move, int player);
void PopOut(int board[MAX_SIZE][MAX_SIZE], int size, char side, int move, int player);

int MakeMove(int board[MAX_SIZE][MAX_SIZE], int size, char side, int move, int player) 
{
    int index = (int)move;

    if (index < 0 || index >= size) 
    {
        printf("Invalid move: index %d is out of range (0-%d).\n", index, size - 1);
        return 0;
    }

    int target_row = -1;
    int target_col = -1;

    if (side == 'T') 
    {
        target_row = 0;
        target_col = index;
    } 
    else if (side == 'B') 
    {
        target_row = size - 1;
        target_col = index;
    } 
    else if (side == 'L') 
    {
        target_row = index;
        target_col = 0;
    } 
    else if (side == 'R') 
    {
        target_row = index;
        target_col = size - 1;
    }
    else 
    {
        printf("Invalid move: '%c' is not a valid side (use T/B/L/R).\n", side);
        return 0;
    }

    if (board[target_row][target_col] == 0) 
    {
        PopIn(board, size, side, move, player);
        return 1;
    }
    else if (board[target_row][target_col] == player) 
    {
        PopOut(board, size, side, move, player);
        return 1;
    }
    else
    {
        printf("Invalid move: entry cell is blocked by the opponent's token.\n");
        return 0;
    }
}