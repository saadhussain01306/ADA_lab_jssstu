#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int selectionSort(int *arr, int n)
{
    int min = 0, count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            count++;
            if (arr[min] > arr[j])
                min = j;
        }
        swap(&arr[min], &arr[i]);
    }
    return count;
}

void main()
{
    FILE *fp;
    int count = 0, *arr = NULL;
    int values[] = {10, 100, 1000, 2000, 5000, 10000, 20000, 40000};
    int n = sizeof(values) / sizeof(values[0]);
    fp = fopen("sel.dat", "a");
    for (int i = 0; i < n; i++)
    {
        int *arr = (int *)malloc(values[i] * sizeof(int));
        for (int j = 0; j < values[i]; j++)
            arr[j] = values[i] - j;
        count = selectionSort(arr, values[i]);
        fprintf(fp, "%d\t%d\n", values[i], count);
        free(arr);
    }
    fclose(fp);
}
