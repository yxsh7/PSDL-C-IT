// SI32 Yash Kamthe
//GITHUB: https://github.com/yxsh7

#include <xc.h>
#include<stdio.h>
#include<stdlib.h>
#include<pic18f4550.h>

void main(void)
{
    int multiplication_result, division_result, num_1, num_2;
    multiplication_result = 0;
    division_result = 0;
    num_1 = 0x01;
    num_2 = 0x02;
    
    multiplication_result = num_1 * num_2;
    division_result = num_2 / num_1;
    
    TRISC = 0;
    PORTC = multiplication_result; 
    
    TRISD = 0; 
    PORTD = division_result;
}
