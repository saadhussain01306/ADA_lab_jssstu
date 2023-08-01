#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int beg, int end, int *count)
{
    int pivot = arr[beg];
    int i = beg, j = end + 1;
    do
    {
        do
        {
            *(count) += 1;
            i++;
        } while (i <= end && arr[i] < pivot);

        do
        {
            *(count) += 1;
            j--;
        } while (j >= beg && arr[j] > pivot);

        if (i < j)
            swap(&arr[i], &arr[j]);

    } while (i < j);
    swap(&arr[beg], &arr[j]);
    return j;
}

void quicksort(int *arr, int beg, int end, int *count)
{
    if (beg < end)
    {
        int split = partition(arr, beg, end, count);
        quicksort(arr, beg, split - 1, count);
        quicksort(arr, split + 1, end, count);
    }
}

void main()
{

    int *arr, n, count;

    srand(time(NULL));
    FILE *f;

    f = fopen("quick_time.txt", "w");

    n = 4;
    while (n < 1034)
    {
        arr = (int *)malloc(sizeof(int) * n);

        // Best case
        count = 0;
        for (int i = 0; i < n; i++)
            arr[i] = 5;
        quicksort(arr, 0, n - 1, &count);
        fprintf(f, "%d\t%d\t", n, count);
        // printf("%d\t%d\t", n, count);

        // worst case
        count = 0;
        for (int i = 0; i < n; i++)
            arr[i] = n - i;
        quicksort(arr, 0, n - 1, &count);
        fprintf(f, "%d\n", count);
        // printf("%d\t%d\n", n, count);

        n = n * 2;

        free(arr);
    }

    fclose(f);
   
}
