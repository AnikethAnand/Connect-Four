#include <stdio.h>
#include <stddef.h>
#include "../include/game.h"
#define MAX_SIZE 10 

// function which takes three inputs: a two-dimensional array of integers, the size of the board, and a string representing the tokens
// that should be initialised on the board.
void InitialiseBoard(int board[MAX_SIZE][MAX_SIZE], int size, char *values) 
{
    // if the initialise string is NULL then the values in the array should be 0
    if (values == NULL) 
    {
        // if NULL set all elements to 0
        for (int row = 0; row < size; row++) 
        {
            for (int col = 0; col < size; col++) 
            {
                board[row][col] = 0;
            }
        }
    } 
    else 
    {
        // Initialize the array
        int i = 0;
        
        for (int row = 0; row < size; row++) 
        {
            for (int col = 0; col < size; col++) 
            {
                
                // Check if its reached the end of the string
                if (values[i] == '\0') 
                {
                    board[row][col] = 0;
                } 
                else 
                {
                    // Check the character and set the value
                    char token = values[i];
                    
                    if (token == 'X') 
                    {
                        board[row][col] = 1;
                    } 
                    else if (token == 'O') 
                    {
                        board[row][col] = 2;
                    } 
                    else 
                    {
                        // If the character is not X or O make it a empty spot
                        board[row][col] = 0;
                    }
                    i++;
                }
            }
        }
    }
}