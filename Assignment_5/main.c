// SI32 Yash Kamthe
// GITHUB: https://github.com/yxsh7

#include <xc.h>        // XC8 Compiler Header File - Includes definitions and configurations for the microcontroller
#include <stdio.h>     // Standard Input/Output Library - Provides functions for input/output operations
#include <string.h>    // String Library - Provides functions for string manipulation

// Function to sort an array in ascending order
void sortAscending(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)   // Loop through the array elements
    {
        for (j = i + 1; j < n; j++)   // Compare each element with the remaining elements
        {
            if (arr[i] > arr[j])      // Swap elements if the current element is greater than the next element
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to sort an array in descending order
void sortDescending(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)   // Loop through the array elements
    {
        for (j = i + 1; j < n; j++)   // Compare each element with the remaining elements
        {
            if (arr[i] < arr[j])      // Swap elements if the current element is less than the next element
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
    int arr[] = {5, 8, 1, 3, 9};    // Declare and initialize an array 'arr' with integers
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the length of the array
    int ascending_arr[5];   // Declare an array 'ascending_arr' to store the ascending order elements
    int descending_arr[5];  // Declare an array 'descending_arr' to store the descending order elements

    sortAscending(arr, n);  // Call the function to sort 'arr' in ascending order
    for (int i = 0; i < n; i++)   // Copy the sorted elements to 'ascending_arr'
    {
        ascending_arr[i] = arr[i];
    }

    sortDescending(arr, n); // Call the function to sort 'arr' in descending order
    for (int i = 0; i < n; i++)   // Copy the sorted elements to 'descending_arr'
    {
        descending_arr[i] = arr[i];
    }
}
