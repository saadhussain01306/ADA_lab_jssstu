// Merge Sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void worst_merge(int a[], int lf[], int rt[], int l, int m, int r)
{
  int i;
  for (i = 0; i <= m - l; i++)
  {
    a[i] = lf[i];
  }
  for (int j = 0; j < r - m; j++)
  {
    a[i + j] = rt[j];
  }
}
void split(int a[], int lf[], int rt[], int l, int m, int r)
{
  int i;
  for (i = 0; i <= m - l; i++)
  {
    lf[i] = a[i * 2];
  }
  for (i = 0; i < r - m; i++)
  {
    rt[i] = a[i * 2 + 1];
  }
}
void gen_worst_data(int a[], int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;
    int lf[m - l + 1];
    int rt[r - m];
    split(a, lf, rt, l, m, r);
    gen_worst_data(lf, l, m);
    gen_worst_data(rt, m + 1, r);
    worst_merge(a, lf, rt, l, m, r);
  }
}
int merge(int b[], int c[], int a[], int n, int m)
{
  int i = 0, j = 0, k = 0, ct = 0;
  while (i < n && j < m)
  {
    if (b[i] < c[j])
    {
      a[k] = b[i];
      i++;
    }
    else
    {
      a[k] = c[j];
      j++;
    }
    k++;
    ct++;
  }
  while (i < n)
  {
    a[k] = b[i];
    i++;
    k++;
  }
  while (j < m)
  {
    a[k] = c[j];
    j++;
    k++;
  }
  return ct;
}
void mergeSort(int a[], int n, int *ct)
{
  int i = 0, j = 0;
  if (n == 1)
    return;
  else
  {
    int b[n / 2];
    int c[n / 2];
    int i, blen = 0, clen = 0;
    for (i = 0; i < n / 2; i++)
    {
      b[i] = a[i];
      blen++;
    }
    i = 0;
    for (j = n / 2; j < n; j++)
    {
      c[i] = a[j];
      i++;
      clen++;
    }
    mergeSort(b, n / 2, ct);
    mergeSort(c, n / 2, ct);
    *(ct) += merge(b, c, a, blen, clen);
  }
}
void main()
{
  srand(time(NULL));
  FILE *f;
  int n = 4, *a, i, ct = 0;
  f = fopen("merge_time.txt", "w");
  while (n < 4096)
  {
    n *= 2;
    ct = 0;
    a = (int *)malloc(n * sizeof(int));

    // best case
    for (i = 0; i < n; i++)
      a[i] = i + 1;
    mergeSort(a, n, &ct);
    // printf("best ct %d\t for n: %d\t", ct, n);
    fprintf(f, "%d\t%d\t", n, ct);


    // worst case
    ct = 0;
    gen_worst_data(a, 0, n - 1);
    mergeSort(a, n, &ct);
    // printf("worst ct %d\t for n: %d\n", ct, n);
    fprintf(f, "%d\n", ct);
  }
  fclose(f);
}
