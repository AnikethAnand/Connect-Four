#include <stdio.h>
#include "../include/game.h"

// Function takes two inputs: a one-dimensional array of integers, and the number of elements in the array
int FourPos(int values[], int length)
{
    // Check if the array length is less than 4
    if (length < 4) 
    {
        return -1; // Return -1 to show you cant get 4 in a row
    }

    // Loop through the array, The loop stops 3 positions before the end to make sure there are always 4 elements left to check
    for (int i = 0; i <= length - 4; i++) 
    {
        // Store the value of the current number being checked
        int first = values[i];

        // Check if the first value is not zero
        if (first != 0) 
        {
            // Check if the next three bumbers are the same to the first one
            if (values[i + 1] == first && values[i + 2] == first && values[i + 3] == first) 
            {
                // If they are the return the starting index
                return i;
            }
        }
    }
    // If the loop finishes without finding any four in a row return -1
    return -1;
}