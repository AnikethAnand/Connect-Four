#include <stdio.h>
#include <stddef.h>
#include "../include/game.h"
#define MAX_SIZE 10 

void PopIn(int board[MAX_SIZE][MAX_SIZE], int size, char side, int move, int player) 
{
    // move is the index which corresponds to the row or column
    int index = (int)move; 

    // Drop from the Top
    if (side == 'T') 
    { 
        // Start at the top row and move down
        for (int r = 0; r < size; r++) 
        {
            if (board[r][index] != 0) 
            {
                if (r == 0) return; // Column is full, no room
                // if it hits another token then place the new token one spot above it
                board[r - 1][index] = player;
                return;
            }
        }
        // if it reaches the bottom of the board then place token in the last row
        board[size - 1][index] = player;
    } 
    
    // Drop from the Bottom
    else if (side == 'B') 
    {
        // Start at the bottom row and move up
        for (int r = size - 1; r >= 0; r--) 
        {
            if (board[r][index] != 0) 
            {
                if (r == size - 1) return; // Column is full, no room
                // if it hits another token then place the new token one spot below it
                board[r + 1][index] = player;
                return;
            }
        }
        // if it reaches the top of the board then place token in the first row
        board[0][index] = player;
    } 
    
    // Drop from the Left
    else if (side == 'L') 
    {
        // Start at the left column and move right
        for (int c = 0; c < size; c++) 
        {
            if (board[index][c] != 0) 
            {
                if (c == 0) return; // Row is full, no room
                // if it hits another token then place the new token one spot to the left
                board[index][c - 1] = player;
                return;
            }
        }
        // if it reaches the right edge of the board then place token in the last column
        board[index][size - 1] = player;
    } 
    
    //Drop from the Right
    else if (side == 'R') 
    {
        // Start at the right column and move left
        for (int c = size - 1; c >= 0; c--) 
        {
            if (board[index][c] != 0) 
            {
                if (c == size - 1) return; // Row is full, no room
                // if it hits another token then place the new token one spot to the right
                board[index][c + 1] = player;
                return;
            }
        }
        // if it reaches the left edge of the board then place token in the first column
        board[index][0] = player;
    }
}