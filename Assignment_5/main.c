// SI32 Yash Kamthe
// GITHUB: https://github.com/yxsh7

#include <xc.h>
#include <stdio.h>
#include<string.h>

void sortAscending(int arr[], int n) 
{
    int i, j, temp;
    for (i = 0; i < n; i++) 
    {
        for (j = i + 1; j < n; j++) 
        {
            if (arr[i] > arr[j]) 
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sortDescending(int arr[], int n) 
{
    int i, j, temp;
    for (i = 0; i < n; i++) 
    {
        for (j = i + 1; j < n; j++) 
        {
            if (arr[i] < arr[j]) 
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void main() 
{   
    int arr[] = {5, 8, 1, 3, 9};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate length of array
    int ascending_arr [5];
    int descending_arr [5];

    sortAscending(arr, n);
    for (int i = 0; i < n; i++)
    {
        ascending_arr[i] = arr[i];
    }
    
    sortDescending(arr,n);
    for (int i = 0; i < n; i++)
    {
        descending_arr[i] = arr[i];
    }
}
