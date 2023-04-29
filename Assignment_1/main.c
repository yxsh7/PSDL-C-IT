// SI32 Yash Kamthe
//GITHUB: https://github.com/yxsh7

#include <xc.h>
#include<stdio.h>
#include<stdlib.h>
#include<pic18f4550.h>

void main(void)
{
    int a,b,sum;
    a=31;
    b=31;
    sum=0;
    TRISD=0;
    
    sum = a+b;
    
    PORTD=sum;
}
