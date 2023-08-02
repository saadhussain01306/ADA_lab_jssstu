#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count = 0;

void genWorst(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        int left[m - l + 1];
        int right[r - m];

        for (int i = 0; i <= m - l; i++)
        {
            left[i] = arr[2 * i];
        }
        for (int i = 0; i < r - m; i++)
        {
            right[i] = arr[2 * i + 1];
        }
        genWorst(left, l, m);
        genWorst(right, m + 1, r);
        int i = 0;
        for (i = 0; i <= m - l; i++)
            arr[i] = left[i];
        for (int j = 0; j < r - m; j++)
            arr[i++] = right[j];
    }
}

void merge(int a[], int b[], int c[], int blen, int clen)
{
    int i = 0, j = 0, k = 0;
    while (i < blen && j < clen)
    {
        if (b[i] <= c[j])
            a[k++] = b[i++];
        else if (b[i] > c[j])
            a[k++] = c[j++];
        count++;
    }
    while (i < blen)
        a[k++] = b[i++];
    while (j < clen)
        a[k++] = c[j++];
}

void mergeSort(int A[], int n)
{
    if (n < 2)
        return;

    int B[n / 2], C[n / 2];

    int k = 0;
    int i = 0;

    for (i = 0; i < n / 2; i++)
        B[i] = A[i];

    int blen = i;

    while (i < n)
        C[k++] = A[i++];

    int clen = k;

    mergeSort(B, n / 2);
    mergeSort(C, n / 2);
    merge(A, B, C, blen, clen);
}

void main()
{
    int *arr = NULL, n;
    srand(time(NULL));
    FILE *fp = fopen("merge2.dat", "a");
    for (int n = 4; n <= 1024; n *= 2)
    {
        arr = (int *)malloc(sizeof(int) * n);

        // best
        count = 0;
        for (int i = 0; i < n; i++)
            arr[i] = i;
        mergeSort(arr, n);
        fprintf(fp, "%d\t%d\t", n, count);


        // worst
        count = 0;
        genWorst(arr, 0, n - 1);
        mergeSort(arr, n);
        fprintf(fp, "%d\n", count);

        free(arr);
    }
    fclose(fp);
}
