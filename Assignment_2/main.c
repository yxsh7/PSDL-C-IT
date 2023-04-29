// SI32 Yash Kamthe
// GITHUB: https://github.com/yxsh7

#include <pic18f4550.h>
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    int i,sum;
    sum = 0;
    int number[] = {1,2,3,4,5,6,7};
    
    for(i=0;i<=6;i++)
    {
        sum = sum + number[i];
    }
    
    TRISD = 0;
    PORTD = sum;
}
