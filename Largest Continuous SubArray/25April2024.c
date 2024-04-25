#include<stdio.h>

int maxSubArraySum(int a[], int n);

int main()
{
   /* int array[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = 9;
    int answer = maxSubArraySum(array , size); */
    int size;
    printf("\n Enter the size of the array you with to check ");
    scanf("%d" , &size);

    int array[size];
    printf("\n Enter the array values of size %d ", size);
    for (int i=0 ; i<size ; i++)
    {
        printf("\n Enter Value at %d ", i+1);
        scanf("%d", &array[i]);
    }
    int answer = maxSubArraySum(array, size);
    printf("\n The value of the maximum contiguous subarray is %d ", answer);
    return 0;
}

int maxSubArraySum(int a[], int n)
{
        int findmax = 0;
        int currentmax = 0;
        for (int i = 0 ; i<n ; i++){
            currentmax = currentmax + a[i];
            if (currentmax < 0)
            {
                currentmax = 0;
            }
            if (currentmax > findmax)
            {
                findmax = currentmax;
            }
        }
        return findmax;
}
