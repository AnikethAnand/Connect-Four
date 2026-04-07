#include <stdio.h>
#include <stddef.h>
#include "../include/game.h"
#define MAX_SIZE 10 

int CheckGameOver(int board[MAX_SIZE][MAX_SIZE], int size);

// function which takes two inputs: a two-dimensional array of integers, and the size of the board. 
void PrintBoard(int board[MAX_SIZE][MAX_SIZE], int size) 
{
    int i, j;
    // Top Border
    printf("--");
    for (j = 0; j < size; j++) 
    {
        printf(" T");
    }
    printf(" --\n");

    // Top Column Headers
    printf("--");
    for (j = 0; j < size; j++) 
    {
        printf(" %d", j);
    }
    printf(" --\n");

    // Print Board Row
    for (i = 0; i < size; i++) 
    {
        // Left Column Marker
        printf("L%d", i);

        // Print the board values
        for (j = 0; j < size; j++) 
        {
            if (board[i][j] == 1) 
            {
                printf(" X");
            } 
            else if (board[i][j] == 2) 
            {
                printf(" O");
            } 
            else 
            {
                printf(" .");
            }
        }
        
        // Right Column Marker
        printf(" %dR\n", i);
    }

    // Bottom Column Headers
    printf("--");
    for (j = 0; j < size; j++) 
    {
        printf(" %d", j);
    }
    printf(" --\n");

    // Bottom Border
    printf("--");
    for (j = 0; j < size; j++) 
    {
        printf(" B");
    }
    printf(" --\n");
}