//SI32 Yash Kamthe
//GITHUB: https://github.com/yxsh7

#include <stdio.h>
#include<string.h>
#define ARRAY_SIZE 7 

#include <stdio.h>     // Standard Input/Output Library - Provides functions for input/output operations
#include <string.h>    // String Library - Provides functions for string manipulation

#define ARRAY_SIZE 7    // Define a constant value for the array size

void main(void)
{
    int source_array[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7};     // Declare and initialize the source array with integers
    int dest_array[ARRAY_SIZE] = {8, 9, 10, 11, 12, 13, 14};  // Declare and initialize the destination array with integers
    int temp;   // Declare a temporary variable to store values during swapping

    for(int i = 0; i < 7; i++)   // BREAKPOINT Loop from i = 0 to i = 6
    {
        temp = dest_array[i];     // Store the value of dest_array[i] in the temporary variable 'temp'
        dest_array[i] = source_array[i];   // Assign the value of source_array[i] to dest_array[i]
        source_array[i] = temp;     // Assign the value of 'temp' to source_array[i]
    }   // BREAKPOINT End of the for loop

}   // End of the main function
