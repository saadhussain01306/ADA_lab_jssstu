// Floyd's Algorithm
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int graph[MAX][MAX];
int cnt=0;

int minimum(int a, int b)
{
    int min = (a < b) ? a : b;
    return min;
}

void floyd(int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            int T = graph[i][k];
            for (int j = 1; j <= n; j++)
            {
                
                if (graph[i][j] > T){
                    graph[i][j] = minimum(graph[i][j], (T + graph[k][j]));cnt++;
                }
            }
        }
    }
}

void main()
{
    int n, i, j;
    printf("\nEnter the number of vertices:\n");
    scanf("%d", &n);
    printf("\nEnter 99 for representing infinity.\n");
    printf("\nEnter the weight matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    floyd(n);

    printf("\nAll pair shortest distance matrix is:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }
    printf("The count for the matrix of %d vertices is %d\n",n,cnt);
}
/*output:-
Enter the number of vertices:
4

Enter 99 for representing infinity.

Enter the weight matrix:
0 99 3 99
2 0 99 99
99 7 0 1
6 99 99 0

All pair shortest distance matrix is:
0  10  3  4  
2  0  5  6  
7  7  0  1  
6  16  9  0  
The count for the matrix of 4 vertices is 24
*/
