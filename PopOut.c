#include <stdio.h>
#include <stddef.h>
#include "../include/game.h"
#define MAX_SIZE 10 

// function which takes five inputs: a two-dimensional array of integers, 
// the size of the board, the side of the board from which a token is being removed, the position (i.e. 
// row or column) on that side, and the player removing the token (i.e. either 1 or 2).
void PopOut(int board[MAX_SIZE][MAX_SIZE], int size, char side, int move, int player) 
{
    // move is the index which corresponds to the row or column
    int index = (int)move;

    // T = Pop-out from the TOP
    if (side == 'T') 
    {
        // Find the topmost token of the player in the column
        for (int r = 0; r < size; r++) 
        {
            if (board[r][index] == player) 
            {
                int i;
                // Shift all tokens BELOW this position UP by one
                for (i = r; i < size - 1; i++) 
                {
                    // Copy the token from the row below into the current row
                    board[i][index] = board[i + 1][index];
                    
                    // If the token just moved up was empty the shift chain stops here
                    if (board[i][index] == 0)
                    {
                        // The empty space is left at the row
                        board[i + 1][index] = 0;
                        return;
                    }
                }
                
                // If the loop finished without hitting an empty spot then the last cell is the new empty spot
                board[size - 1][index] = 0;
                return;
            }
        }
    }

    // B = Pop-out from the BOTTOM
    if (side == 'B') 
    {
        // Find the bottommost token of player
        for (int r = size - 1; r >= 0; r--) 
        {
            if (board[r][index] == player) 
            {
                int i;
                // Shift all tokens above this position DOWN by one
                for (i = r; i > 0; i--) 
                {
                    // Copy the token from the row above into the current row
                    board[i][index] = board[i - 1][index];
                    
                    // If the token just moved down was empty the shift chain stops here
                    if (board[i][index] == 0)
                    {
                        // The empty space is left at the row
                        board[i - 1][index] = 0;
                        return;
                    }
                }

                // The top cell in the column is now empty
                board[0][index] = 0;
                return;
            }
        }
    }

    // L = Pop-out from the LEFT
    if (side == 'L') 
    {
        // Find the leftmost token of player
        for (int c = 0; c < size; c++) 
        {
            if (board[index][c] == player) 
            {
                int j;
                // Shift all tokens to the right of this position LEFT by one
                for (j = c; j < size - 1; j++) 
                {
                    // Copy the token from the column to the right into the current column
                    board[index][j] = board[index][j + 1];
                    
                    // If the token just moved left was empty the shift chain stops here
                    if (board[index][j] == 0)
                    {
                        // The empty space is left at the column
                        board[index][j + 1] = 0;
                        return;
                    }
                }

                // The rightmost cell in the row is now empty
                board[index][size - 1] = 0;
                return;
            }
        }
    }

    // R = Pop-out from the RIGHT
    if (side == 'R') 
    {
        // Find the rightmost token of player
        for (int c = size - 1; c >= 0; c--) 
        {
            if (board[index][c] == player) 
            {
                int j;
                // Shift all tokens to the left of this position RIGHT by one
                for (j = c; j > 0; j--) 
                {
                    // Copy the token from the column to the left into the current column
                    board[index][j] = board[index][j - 1];
                    
                    // If the token just moved right was empty then the shift chain stops here
                    if (board[index][j] == 0)
                    {
                        // The empty space is left at the column
                        board[index][j - 1] = 0;
                        return;
                    }
                }

                // The leftmost cell in the row is now empty
                board[index][0] = 0;
                return;
            }
        }
    }
}