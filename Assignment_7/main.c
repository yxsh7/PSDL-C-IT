// SI32 Yash Kamthe
// GITHUB: https://github.com/yxsh7

#include <pic18f4550.h>   // PIC18F4550 Header File - Contains specific definitions for the PIC18F4550 microcontroller

#define Buzzer LATAbits.LATA5   // Define Buzzer pin as LATA5 (pin connected to the buzzer)

unsigned int count = 0;    // Declare and initialize a variable to count the number of Timer1 interrupts

void __interrupt() Timer1_ISR()    // Timer1 interrupt service routine
{
    if(TMR1IF==1)   // Check if Timer1 interrupt flag is set
    {
        //TMR1=0xCF2C;
        TMR1L = 0x20;   // Load Timer1 low register with 0x20
        TMR1H = 0xD1;   // Load Timer1 high register with 0xD1
        count++;    // Increment the count variable

        if (count >= 10)    // If the count reaches 10
        {
            Buzzer = ~Buzzer;   // Toggle the state of the Buzzer pin
            count = 0;    // Reset the count variable
        }

        TMR1IF = 0;   // Clear the Timer1 interrupt flag
    }
}

void main()
{
    TRISB = 0;   // Set all pins of PORTB as output
    GIE = 1;    // Enable global interrupts
    TRISAbits.TRISA5 = 0;   // Set pin LATA5 (connected to the buzzer) as output
    TMR1L = 0x20;   // Load Timer1 low register with 0x20
    PEIE = 1;   // Enable peripheral interrupts
    TMR1IE = 1;   // Enable Timer1 interrupt
    TMR1IF = 0;   // Clear Timer1 interrupt flag
    T1CON = 0x80;   // Configure Timer1 control register
    TMR1H = 0xD1;   // Load Timer1 high register with 0xD1
    TMR1ON = 1;   // Turn on Timer1
    while(1);   // Infinite loop
}

