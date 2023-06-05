// SI32 Yash Kamthe
// GITHUB: https://github.com/yxsh7

#include <pic18f4550.h>   // PIC18F4550 Header File - Contains specific definitions for the PIC18F4550 microcontroller

#define RELAY_PIN LATAbits.LATA4   // Define RELAY_PIN as LATA4 (pin connected to the relay)

void __interrupt() extint_isr(void)    // External interrupt service routine
{
    unsigned int i;    // Declare an unsigned integer variable
    
    if (INT1F)    // Check if the INT1 external interrupt flag is set
    {
        INT1IF = 0;    // Clear the INT1 interrupt flag
        INT1E = 0;    // Disable the INT1 external interrupt
        RELAY_PIN = ~RELAY_PIN;    // Toggle the state of the RELAY_PIN
        for (i = 0; i < 1000; i++)    // Delay loop
        {
            INT1IE = 1;    // Enable the INT1 external interrupt
        }
    }
}

int main()
{
    ADCON1 = 0x0F;    // Configure ADCON1 register
    
    TRISAbits.TRISA4 = 0;    // Set pin LATA4 (connected to the relay) as output
    TRISBbits.TRISB1 = 1;    // Set pin RB1 (connected to the external interrupt) as input
    
    RELAY_PIN = 1;    // Set the initial state of the relay pin
    
    INT1IE = 1;    // Enable the INT1 external interrupt
    INTEDG1 = 0;    // Set the INT1 external interrupt on the falling edge
    GIE = 1;    // Enable global interrupts
    
    while (1);    // Infinite loop
}


