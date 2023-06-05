// SI32 Yash Kamthe
// GITHUB: https://github.com/yxsh7

#include <xc.h>         // XC8 Compiler Header File - Includes definitions and configurations for the PIC18F4550 microcontroller
#include <stdio.h>      // Standard Input/Output Library - Provides functions for input/output operations
#include <stdlib.h>     // Standard Library - Provides functions for general purpose operations
#include <pic18f4550.h> // PIC18F4550 Header File - Contains specific definitions for the PIC18F4550 microcontroller

void main(void)
{
    int a, b, sum;   // Declare variables 'a', 'b', and 'sum' of type int
    a = 31;          // Assign 31 to variable 'a'
    b = 31;          // Assign 31 to variable 'b'
    sum = 0;         // Initialize variable 'sum' to 0
    TRISD = 0;       // Set all pins of PORTD as output

    sum = a + b;     // Add variables 'a' and 'b', and store the result in 'sum'

    PORTD = sum;     // Assign the value of 'sum' to PORTD
}

