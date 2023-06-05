// SI32 Yash Kamthe
// GITHUB: https://github.com/yxsh7

#include <xc.h>             // XC8 Compiler Header File - Includes definitions and configurations for the microcontroller
#include <pic18f4550.h>    // PIC18F4550 Header File - Contains specific definitions for the PIC18F4550 microcontroller

void delay(unsigned int time) {
    unsigned int i, j;
    for(i = 0; i < time; i++) {     // Outer loop for delaying 'time' number of times
        for(j = 0; j < 5000; j++) {}    // Inner loop for delaying a fixed number of iterations
    }   
}

void main(void) {
    TRISB = 0x00;           // Set all pins of PORTB as output
    
    while(1) {
        LATB = 0xAA;        // Assign the hexadecimal value 0xAA to PORTB, setting alternate pins high
        delay(200);         // Delay for a certain duration
        
        LATB = 0x55;        // Assign the hexadecimal value 0x55 to PORTB, setting alternate pins low
        delay(200);         // Delay for a certain duration
    }
}
