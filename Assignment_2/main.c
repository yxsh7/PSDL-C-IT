// SI32 Yash Kamthe
// GITHUB: https://github.com/yxsh7

#include <pic18f4550.h>  // PIC18F4550 Header File - Contains specific definitions for the PIC18F4550 microcontroller
#include <xc.h>          // XC8 Compiler Header File - Includes definitions and configurations for the PIC18F4550 microcontroller
#include <stdio.h>       // Standard Input/Output Library - Provides functions for input/output operations
#include <stdlib.h>      // Standard Library - Provides functions for general-purpose operations

void main(void)
{
    int i, sum;          // Declare variables 'i' and 'sum' of type int
    sum = 0;             // Initialize variable 'sum' to 0
    int number[] = {1, 2, 3, 4, 5, 6, 7};  // Declare and initialize an array 'number' with integers

    for(i = 0; i <= 6; i++)  // Loop from i = 0 to i = 6
    {
        sum = sum + number[i];  // Add the value of 'number[i]' to 'sum'
    }

    TRISD = 0;           // Set all pins of PORTD as output
    PORTD = sum;         // Assign the value of 'sum' to PORTD, which will display the sum on PORTD pins
}
