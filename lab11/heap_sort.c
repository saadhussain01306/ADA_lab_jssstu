#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int i, int n)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    count++;
    if (left <= n && arr[left] > arr[largest])
        largest = left;
    if (right <= n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);
        heapify(arr, largest, n);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2; i >= 1; i--)
        heapify(arr, i, n);

    for (int i = n; i > 1; i--)
    {
        swap(&arr[1], &arr[i]);
        heapify(arr, 1, i - 1);
    }
}

void main()
{
    int n;
    srand(time(NULL));
    FILE *fp = fopen("heap2.dat", "a");
    int *a = NULL;
    for (n = 10; n <= 100; n += 10)
    {
        a = (int *)malloc(sizeof(int) * (n + 1));

        // best case
        count = 0;
        for (int i = 1; i <= n; i++)
            a[i] = n;
        heapSort(a, n);
        fprintf(fp, "%d\t%d\t", n, count);

        count = 0;
        for (int i = 1; i <= n; i++)
            a[i] = rand() % n;
        heapSort(a, n);
        fprintf(fp, "%d\t", count);

        count = 0;
        for (int i = 1; i <= n; i++)
            a[i] = i;
        heapSort(a, n);
        fprintf(fp, "%d\n", count);
    }
    fclose(fp);
}
