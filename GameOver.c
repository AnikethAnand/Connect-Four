#include <stdio.h>
#include <stddef.h>
#include "../include/game.h"
#define MAX_SIZE 10 

// function which takes two inputs: a two-dimensional array of integers, and the size of the board
int CheckGameOver(int board[MAX_SIZE][MAX_SIZE], int size)
{
    int has_empty_spot = 0;
    // Variables to track if Player 1 or Player 2 has a winning line anywhere on the board
    int p1_wins = 0; 
    int p2_wins = 0;
    
    // Check every cell for a win condition and look for an empty spot
    for (int r = 0; r < size; r++) 
    {
        for (int c = 0; c < size; c++) 
        {
            // If cell is taken then check for a win streak
            if (board[r][c] != 0) 
            {
                int winner = FourInARow(board, size, r, c);
                
                // Track all winning lines found across the board
                if (winner == 1) 
                {
                    p1_wins = 1;
                }
                else if (winner == 2)
                {
                    p2_wins = 1;
                }
            }
            // If a spot is empty then the board is not full
            else 
            {
                has_empty_spot = 1;
            }
        }
    }
    
    if (p1_wins && p2_wins) 
    {
        return 3; // Both win = 3
    } 
    else if (p1_wins) 
    {
        return 1; // Player 1 wins = 1
    } 
    else if (p2_wins) 
    {
        return 2; // Player 2 wins = 2
    } 

    // No winner found
    else 
    {
        if (has_empty_spot) 
        {
            return 0; // Both lose or Game continues
        } 
        else 
        {
            // Board is full so no winner found
            return 0; 
        }
    }
}