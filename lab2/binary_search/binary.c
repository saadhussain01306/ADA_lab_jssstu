#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int *arr, int low, int high, int key, int *count)
{
    if (low > high)
    {
        *count += 1;
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == key)
    {
        *count += 2;
        return mid;
    }
    else if (arr[mid] < key)
    {
        *count += 3;
        return binarySearch(arr, mid + 1, high, key, count);
    }
    else
    {
        *count += 3;
        return binarySearch(arr, low, mid - 1, key, count);
    }
}
void main()
{
    srand(time(NULL));
    int count = 0;
    int x, size = 1, key = 0;
    FILE *fptr = fopen("binary.dat", "a");
    while (size < 40000)
    {
        if (size < 1000)
            size *= 10;
        else
            size *= 2;
        fprintf(fptr, "%d\t", size);

        int *arr = (int *)malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++)
            arr[i] = i + 1;
        // best case
        x = binarySearch(arr, 0, size - 1, arr[(size - 1) / 2], &count);
        fprintf(fptr, "%d\t", count);
        count = 0;


        // worst case
        x = binarySearch(arr, 0, size - 1, arr[size - 1], &count);
        fprintf(fptr, "%d\n", count);
        count = 0;

        free(arr);
    }

    fclose(fptr);
    
}
