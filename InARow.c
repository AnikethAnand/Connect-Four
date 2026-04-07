#include <stdio.h>
#include <stddef.h>
#define MAX_SIZE 10 

int FourInARow(int board[MAX_SIZE][MAX_SIZE], int size, int row, int col) 
{
    // either the first or second player whose move we are checking
    int player = board[row][col];
    
    // cell is empty so it cant be winning move
    if (player == 0) 
    {
        return 0;
    }

    // We need 4 directions which are Horizontal, Vertical, and the 2 Diagonals
    int directions[4][2] = 
    {
        {0, 1},
        {1, 0},
        {1, 1},
        {1, -1}
    };

    // go through the all 4 winning directions
    for (int i = 0; i < 4; i++) 
    {
        int drow = directions[i][0];
        int dcol = directions[i][1];
        
        // This count is for the sequence running in one line
        int max_streak = 1;
        
        // Check in the POSITIVE direction
        for (int k = 1; ; k++) 
        { 
            int new_row = row + k * drow;
            int new_col = col + k * dcol;
            
            // Check boundaries and if the token belongs to the same player
            if (new_row >= 0 && new_row < size && new_col >= 0 && new_col < size && board[new_row][new_col] == player) 
            {
                max_streak++;
            } 
            else 
            {
                // Breaks if out of bounds OR streak is broken
                break; 
            }
        }

        // Check in the NEGATIVE direction
        for (int k = 1; ; k++) 
        {
            int new_row = row - k * drow;
            int new_col = col - k * dcol;
            
            // Check boundaries and if the token belongs to the current player
            if (new_row >= 0 && new_row < size && new_col >= 0 && new_col < size && board[new_row][new_col] == player) 
            {
                max_streak++;
            } 
            else 
            {
                // Breaks if out of bounds or streak is broken
                break; 
            }
        }

        // If the total streak in this line is 4 or more you win
        if (max_streak >= 4) 
        {
            return player;
        }
    }

    // No four-in-a-row found in any direction
    return 0;
}