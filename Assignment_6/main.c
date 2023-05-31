// SI32 Yash Kamthe
// GITHUB: https://github.com/yxsh7

#include <xc.h>
#include <pic18f4550.h>

void delay(unsigned int time){
    unsigned int i,j;
    for(i = 0; i<time; i++){
        for(j =0; j<5000; j++){}
    }   
}
void main(void) {
    TRISB = 0x00;
    while(1){
        LATB = 0xAA;
        delay(200);
        LATB = 0x55;
        delay(200);
    }
}
