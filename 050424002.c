#include <stdio.h>

void checksum(int arr[], int size);
int sequentialsearch(int arr[], int size, int value);
int binarysearch(int arr[], int size, int value);
int recursivebinarysearch(int arr[], int first, int last, int value);

int main()
{
    int arr[] = {1,2,3,4,5};
    int size = 5;

    // checksum(arr, size);
    // sequentialsearch(arr,size,3);
    printf("\nBinary search start");
    int result = binarysearch(arr,size,4);
    (result == -1) ? printf("\nElement is not present in the array") : printf("\nElement is present at index %d", result + 1);
    printf("\nBinary search end");
    printf("\nRecursive Binary search start");
    int resulttwo = recursivebinarysearch(arr,0,size-1,4);
    (resulttwo == -1) ? printf("\nElement is not present in the array") : printf("\nElement is present at index %d", resulttwo + 1);
    printf("\nRecursive Binary search end");

}

void checksum(int arr[], int size)
{
    int total = 0;
    for (int i = 0; i<size; i++)
    {
        total = total + arr[i];
    }
    printf("\nTotal size is %d", total);
}

// sequential search
int sequentialsearch(int arr[], int size, int value)
{
    for (int i = 0; i<size ; i++)
    {
        if(value == arr[i])
        {
            printf("\nThe value is here.");
            return i;
        }
    }
    return -1;
}

// binary search - if data is sorted
/* - you search for the middle position
   - what do you get. you get to compare the value at the middle of the array with the value we are searching for
   - if this value is greater than it, it means it is at the right
   - therefore we reduce the space to the right. (high = mid - 1)
   - or rather, we search the right half of the array
   - Now Immanuel you have to see it
   - what are we trying to do. 
   - if it is greater, we want to go to the right. and search that side. 
   - what are we going to do
   - continue thinking

   Analysis:
· Since we have data sorted in increasing / decreasing order, we can apply more efficient binary search.
At each step, we reduce our search space by half.
· At each step, we compare the middle value with the value we are searching. If mid value is equal to the
value we are searching for then we return the middle index.
· If the value is smaller than the middle value, we search the left half of the array.
· If the value is greater than the middle value then we search the right half of the array.
· If we find the value we are looking for then its index is returned or -1 is returned otherwise.

GPT 
else if (arr[mid] < value): If the value at the middle index is less than the target value, it means that the target value should be located in the right half of the current segment, so we update the low index to mid + 1.

else: If the value at the middle index is greater than the target value, it means that the target value should be located in the left half of the current segment, so we update the high index to mid - 1.

By adjusting the low and high indices in each iteration, the algorithm effectively reduces the search space by half with each iteration. It continues this process until either the value is found or the low index becomes greater than the high index, indicating that the value is not present in the array.

Overall, this binary search algorithm has a time complexity of O(log n), making it much more efficient than a linear search algorithm, especially for large arrays.
*/
int binarysearch(int arr[], int size, int value)
{
    int low = 0,mid;
    int high = size - 1;
    while (low <= high)
    {
        mid = low + (high-low)/2; // to avoid overflow
        if (arr[mid] == value)
        {
            return mid;
        } else if(value > arr[mid])
        {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }

    }
    return -1;

}

int recursivebinarysearch(int arr[], int first, int last, int value)
{
    if (first <= last)
    {
        int mid = first + (last - first) / 2;
        if (arr[mid] == value)
        {
            return mid;
        } else if (value > arr[mid])
        {
            return recursivebinarysearch(arr, mid + 1 , last, value);
        } else 
        {
            return recursivebinarysearch(arr,first, mid - 1, value);
        }
    }
    return -1;
}