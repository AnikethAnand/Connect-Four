#include <stdio.h>
#include "../include/game.h"
#define MAX_SIZE 10 

// function that takes two inputs: a 2-dimensional array of integers, and the size of the board.
void PrintGrid(int board[MAX_SIZE][MAX_SIZE], int size) 
{
    // Print the top border size + 2 # caracters
    for (int i = 0; i < (2 * size + 1); i++) 
    {
        printf("#");
    }
    printf("\n");

    // Print the grid rows
    for (int r = 0; r < size; r++) 
    {
        printf("#");
        for (int c = 0; c < size; c++) 
        {
            printf("%d", board[r][c]);
            // Print a space after the number unless its the last column
            if (c < size - 1) 
            {
                printf(" ");
            }
        }
        printf("#\n");
    }

    // Print the bottom border
    for (int i = 0; i < (2 * size + 1); i++) 
    {
        printf("#");
    }
    printf("\n");
}