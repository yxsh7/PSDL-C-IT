// SI32 Yash Kamthe
// GITHUB: https://github.com/yxsh7

#include <stdio.h>
#include<string.h>
#define ARRAY_SIZE 7 

void main(void)
{
  int source_array[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7}; 
  int dest_array[ARRAY_SIZE] = {8, 9, 10, 11, 12, 13, 14};
  int temp;
 
  for(int i=0; i<7; i++) // breakpoint
  {
      temp = dest_array[i];
      dest_array[i] = source_array[i];
      source_array[i] = temp;
  } // breakpoint
 
} 
