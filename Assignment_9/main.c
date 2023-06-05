// SI32 Yash Kamthe
// GITHUB: https://github.com/yxsh7

#include <pic18f4550.h>   // PIC18F4550 Header File - Contains specific definitions for the PIC18F4550 microcontroller

#define LCD_EN LATAbits.LA1   // Define LCD_EN as LATA1 (pin connected to the enable pin of the LCD)
#define LCD_RS LATAbits.LA0   // Define LCD_RS as LATA0 (pin connected to the register select pin of the LCD)
#define LCDPORT LATB   // Define LCDPORT as LATB (port connected to the data pins of the LCD)

void lcd_delay(unsigned int time)
{
    unsigned int i, j;
    for (i = 0; i < time; i++)
    {
        for (j = 0; j < 100; j++)
        {
            // Delay loop
        }
    }
}

void SendInstruction(unsigned char command)
{
    LCD_RS = 0;   // Set RS pin low to select instruction mode
    LCDPORT = command;   // Send the command to the LCD data pins
    LCD_EN = 1;   // Set EN pin high to enable the LCD
    lcd_delay(10);   // Delay to ensure proper timing
    LCD_EN = 0;   // Set EN pin low to disable the LCD
    lcd_delay(10);   // Delay to ensure proper timing
}

void SendData(unsigned char lcddata)
{
    LCD_RS = 1;   // Set RS pin high to select data mode
    LCDPORT = lcddata;   // Send the data to the LCD data pins
    LCD_EN = 1;   // Set EN pin high to enable the LCD
    lcd_delay(10);   // Delay to ensure proper timing
    LCD_EN = 0;   // Set EN pin low to disable the LCD
    lcd_delay(10);   // Delay to ensure proper timing
}

void InitLCD(void)
{
    ADCON1 = 0x0F;   // Configure ADCON1 register
    
    TRISAbits.RA0 = 0;   // Set pin RA0 (LCD RS pin) as output
    TRISAbits.RA1 = 0;   // Set pin RA1 (LCD EN pin) as output
    
    SendInstruction(0x38);   // Send LCD initialization command - 2 lines, 5x8 font
    SendInstruction(0x06);   // Entry mode set - increment cursor, no shift
    SendInstruction(0x0C);   // Display ON, cursor OFF, blink OFF
    SendInstruction(0x01);   // Clear display
    SendInstruction(0x80);   // Set cursor to the first position of the first line
}

unsigned char *String1 = "SPPU 2021-22";   // First line of text to display
unsigned char *String2 = "PSDL";   // Second line of text to display

void main(void)
{
    ADCON1 = 0x0F;   // Configure ADCON1 register
    
    TRISAbits.RA0 = 0;   // Set pin RA0 (LCD RS pin) as output
    TRISAbits.RA1 = 0;   // Set pin RA1 (LCD EN pin) as output
    TRISB = 0x00;   // Set all pins of PORTB as output
    
    SendInstruction(0x38);   // Send LCD initialization command - 2 lines, 5x8 font
    SendInstruction(0x06);   // Entry mode set - increment cursor, no shift
    SendInstruction(0x0C);   // Display ON, cursor OFF, blink OFF
    SendInstruction(0x01);   // Clear display
    SendInstruction(0x80);   // Set cursor to the first position of the first line
    
    while (*String1)
    {
        SendData(*String1);   // Send each character of String1 to display
        String1++;
    }
    
    SendInstruction(0x0C);   // Display ON, cursor OFF, blink OFF
    
    while (*String2)
    {
        SendData(*String2);   // Send each character of String2 to display
        String2++;
    }
    
    while (1);   // Infinite loop
}


