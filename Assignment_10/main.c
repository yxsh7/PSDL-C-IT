// SI32 Yash Kamthe
// GITHUB: https://github.com/yxsh7

#include <xc.h>
#include <pic18f4550.h>
#include <stdio.h>

#define LCD_EN LATAbits.LA1   // Define LCD_EN as LATA1 (pin connected to the enable pin of the LCD)
#define LCD_RS LATAbits.LA0   // Define LCD_RS as LATA0 (pin connected to the register select pin of the LCD)
#define LCDPORT LATB   // Define LCDPORT as LATB (port connected to the data pins of the LCD)

unsigned char str[10];   // Declare a character array to store the converted temperature string

void delay(unsigned int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 150; j++)
        {
            // Delay loop
        }
    }
}

void sendData(unsigned char c)
{
    LCD_RS = 1;   // Set RS pin high to select data mode
    LCD_EN = 1;   // Set EN pin high to enable the LCD
    delay(10);   // Delay to ensure proper timing
    LCDPORT = c;   // Send the data to the LCD data pins
    LCD_EN = 0;   // Set EN pin low to disable the LCD
    delay(10);   // Delay to ensure proper timing
}

void sendCommand(unsigned char c)
{
    LCD_RS = 0;   // Set RS pin low to select instruction mode
    LCD_EN = 1;   // Set EN pin high to enable the LCD
    delay(10);   // Delay to ensure proper timing
    LCDPORT = c;   // Send the command to the LCD data pins
    LCD_EN = 0;   // Set EN pin low to disable the LCD
    delay(10);   // Delay to ensure proper timing
}

void LCD_init()
{
    ADCON1 = 0x0F;   // Configure ADCON1 register
    
    TRISB = 0x00;   // Set all pins of PORTB as output
    TRISAbits.RA0 = 0;   // Set pin RA0 (LCD RS pin) as output
    TRISAbits.RA1 = 0;   // Set pin RA1 (LCD EN pin) as output
    
    sendCommand(0x38);   // Send LCD initialization command - 2 lines, 5x8 font
    sendCommand(0x06);   // Entry mode set - increment cursor, no shift
    sendCommand(0xC0);   // Set DDRAM address to the beginning of the second line
    sendCommand(0x01);   // Clear display
    sendCommand(0x80);   // Set DDRAM address to the beginning of the first line
}

void ADC_init()
{
    TRISEbits.RE2 = 1;   // Set pin RE2 as input for ADC
    ADCON1 = 0b00000111;   // Configure ADCON1 register - Right justify, Vref+ is connected to VDD, Vref- is connected to VSS
    ADCON2 = 0b10101110;   // Configure ADCON2 register - Acquisition time = 12 TAD, Conversion clock = FOSC/64, ADC result is right-justified, Conversion trigger is enabled by setting GO/DONE bit
}

void display(unsigned int row, unsigned int position, unsigned char *c)
{
    if (row == 1)
        sendCommand(0x80 | (position - 1));   // Set DDRAM address to the specified position of the first line
    else
        sendCommand(0xC0 | (position - 1));   // Set DDRAM address to the specified position of the second line
    
    while (*c)
    {
        sendData(*c++);   // Send each character of the string to the LCD
    }
}

unsigned short read_temp()
{
    ADCON0 = 0b00011101;   // Configure ADCON0 register - Select channel AN9 (connected to RE2)
    GODONE = 1;   // Start ADC conversion by setting the GO/DONE bit
    while (GO_DONE == 1)   // Wait for the conversion to complete
    {
        return ADRES;   // Return the result of the ADC conversion
    }
}

int main()
{
    unsigned int temp;
    LCD_init();   // Initialize the LCD
    ADC_init();   // Initialize the ADC
    
    display(1, 1, "Temperature");   // Display "Temperature" on the first line of the LCD
    
    while (1)
    {
        temp = read_temp();   // Read the temperature using ADC
        temp = ((temp * 500) / 1023);   // Convert ADC value to temperature in degrees Celsius
        sprintf(str, "%dC", temp);   // Convert temperature to a string
        
        display(2, 1, str);   // Display the temperature on the second line of the LCD
        
        delay(100000);   // Delay before updating the temperature display
    }
    
    return 0;
}


