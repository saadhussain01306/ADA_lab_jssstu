#include <stdio.h>
#include <stdlib.h>

int strMatch(char *str, char *pattern, int m, int n)
{
    int count = 0;
    for (int i = 0; i < m - n + 1; i++)
    {
        int j = 0;
        while (j < n && str[i + j] == pattern[j])
        {
            count++;
            j++;
        }
        if (j == n)
            return count;
        count++;
    }
    return count;
}

void main()
{
    FILE *fp;
    fp = fopen("str.dat", "a");
    int m = 1000;
    char str[1000];
    for (int i = 0; i < m; i++)
        str[i] = 'a';
    for (int i = 100; i <= m; i += 100)
    { // i represents size of pattern

        fprintf(fp, "%d\t", i);
        char pattern[i];
        for (int j = 0; j < i; j++)
            pattern[j] = 'a';

        // Best Case
        fprintf(fp, "%d\t", strMatch(str, pattern, m, i));

        // Worst Case
        pattern[i - 1] = 'b';
        fprintf(fp, "%d\n", strMatch(str, pattern, m, i));
    }
    fclose(fp);
}
