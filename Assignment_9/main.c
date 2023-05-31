// SI32 Yash Kamthe
// GITHUB: https://github.com/yxsh7

#include <xc.h>
#include <pic18f4550.h>
#define LCD_RS LATAbits.LA0
#define LCD_EN LATAbits.LA1
#define LCDPORT LATB
void lcd_delay(unsigned int time){
    unsigned int i,j;
    for(i = 0; i< time; i++){
        for(j=0;j<100;j++){}
    }
}
void SendInstruction(unsigned char command){
    LCD_RS=0;
    LCDPORT = command;
    LCD_EN = 1;
    lcd_delay(10);
    LCD_EN = 0;
    lcd_delay(10);
}
void SendData(unsigned char lcdData){
    LCD_RS = 1;
    LCDPORT = lcdData;
    LCD_EN = 1;
    lcd_delay(10);
    LCD_EN = 0;
    lcd_delay(10);
}
void initLCD(void){
    ADCON1 = 0x0F;
    TRISB = 0x00;
    TRISAbits.RA0 = 0;
    TRISAbits.RA1 = 0;
    SendInstruction(0x38);
    SendInstruction(0x06);
    SendInstruction(0x0C);
    SendInstruction(0x01);
    SendInstruction(0x80);
}
unsigned char *String1 = "Arundhati Rujuta";
unsigned char *String2 = "Anushka";
void main(void) {
    initLCD();
    while(*String1){
        SendData(*String1);
        String1++;
    }
    SendInstruction(0xC0);
    while(*String2){
        SendData(*String2);
        String2++;
    }
    while(1);
}
