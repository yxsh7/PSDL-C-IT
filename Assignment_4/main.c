// SI32 Yash Kamthe
//GITHUB: https://github.com/yxsh7

#include <xc.h>         // XC8 Compiler Header File - Includes definitions and configurations for the PIC18F4550 microcontroller
#include <stdio.h>      // Standard Input/Output Library - Provides functions for input/output operations
#include <stdlib.h>     // Standard Library - Provides functions for general-purpose operations
#include <pic18f4550.h> // PIC18F4550 Header File - Contains specific definitions for the PIC18F4550 microcontroller

void main(void)
{
    int multiplication_result, division_result, num_1, num_2;    // Declare variables 'multiplication_result', 'division_result', 'num_1', and 'num_2' of type int
    multiplication_result = 0;                                  // Initialize variable 'multiplication_result' to 0
    division_result = 0;                                        // Initialize variable 'division_result' to 0
    num_1 = 0x01;                                               // Assign the hexadecimal value 0x01 to 'num_1'
    num_2 = 0x02;                                               // Assign the hexadecimal value 0x02 to 'num_2'
    
    multiplication_result = num_1 * num_2;                      // Perform multiplication of 'num_1' and 'num_2', and store the result in 'multiplication_result'
    division_result = num_2 / num_1;                            // Perform division of 'num_2' by 'num_1', and store the result in 'division_result'
    
    TRISC = 0;                                                  // Set all pins of PORTC as output
    PORTC = multiplication_result;                              // Assign the value of 'multiplication_result' to PORTC, which will display the multiplication result on PORTC pins
    
    TRISD = 0;                                                  // Set all pins of PORTD as output
    PORTD = division_result;                                    // Assign the value of 'division_result' to PORTD, which will display the division result on PORTD pins
}
