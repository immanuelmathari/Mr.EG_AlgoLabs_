#include<stdio.h>

int main()
{
    int arr[10];
    for (int i = 0; i<10 ; i++)
    {
        arr[i] = i;
    }
    printArray(arr,10);
}

void printArray(int arr[], int count)
{
    printf("Elements in the array are\n");
    
    for (int i=0 ; i<count ; i++)
    {
        printf("[%d]",arr[i]);
    }
}