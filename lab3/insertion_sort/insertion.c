#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int insertionSort(int *arr, int n)
{
    int count = 0, flag = 0;
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        if (arr[j] < temp)
            count++;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            count++;
        }
        // count++; // doubt between this line andline 19
        arr[j + 1] = temp;
    }
    return count;
}

void main()
{
    FILE *fp;
    srand(time(NULL));
    int count = 0, *arr = NULL;
    int values[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(values) / sizeof(values[0]);
    fp = fopen("ins.dat", "a");
    for (int i = 0; i < n; i++)
    {
        int *arr = (int *)malloc(values[i] * sizeof(int));

        // Best Case I/P
        for (int j = 0; j < values[i]; j++)
            arr[j] = j;
        count = insertionSort(arr, values[i]);
        fprintf(fp, "%d\t%d\t", values[i], count);


        //  Worst Case I/P
        for (int j = 0; j < values[i]; j++)
            arr[j] = values[i] - j;
        count = insertionSort(arr, values[i]);
        fprintf(fp, "%d\n", count);

        free(arr);
    }
    fclose(fp);
}
