// SI32 Yash Kamthe
// GITHUB: https://github.com/yxsh7

#include <pic18f4550.h>
#define Buzzer LATAbits.LATA5
unsigned int count = 0;
void __interrupt() Timer1_ISR()
{
    if(TMR1IF==1)
    {
        //TMR1=0xCF2C;
        TMR1L = 0x20;
        TMR1H = 0xD1;
        count ++;
        if (count >= 10)
        {
            Buzzer = ~Buzzer;
            count = 0;
        }
        TMR1IF = 0;
    }
}

void main()
{
    TRISB=0;
    GIE=1;
    TRISAbits.TRISA5 = 0;
    TMR1L = 0x20;
    PEIE=1;
    TMR1IE=1;
    TMR1IF=0;
    T1CON=0x80;
    TMR1H = 0xD1;
    TMR1ON=1;
    while(1);
}
