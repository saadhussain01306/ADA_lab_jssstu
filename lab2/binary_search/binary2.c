#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count = 0;

int binary(int arr[], int key, int l, int r)
{
    if (l > r)
    {
        return -1;
    }
    int m = (l + r) / 2;
    count += 1;
    if (arr[m] == key)
    {
        return m;
    }
    else if (arr[m] < key)
    {
        return binary(arr, key, m + 1, r);
    }
    else
    {
        return binary(arr, key, l, m - 1);
    }
}

void main()
{
    int *arr = NULL;
    int n = 10, key;
    srand(time(NULL));
    int size[] = {10, 100, 1000, 2000, 4000, 8000, 16000, 32000, 64000};
    FILE *fp = fopen("binary2.dat", "a");

    for (n = 0; n < 9; n++)
    {
        arr = (int *)malloc(sizeof(int) * size[n]);
        for (int i = 0; i < size[n]; i++)
            arr[i] = i;

        // Best
        count = 0;
        binary(arr, arr[(size[n] - 1) / 2], 0, size[n] - 1);
        fprintf(fp, "%d\t%d\t", size[n], count);

        // Avg
        count = 0;
        binary(arr, arr[rand() % size[n]], 0, size[n] - 1);
        fprintf(fp, "%d\t", count);

        // Worst
        count = 0;
        binary(arr, arr[size[n] - 1], 0, size[n] - 1);
        fprintf(fp, "%d\n", count);

        free(arr);
    }
    fclose(fp);
}
