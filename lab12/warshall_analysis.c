// Warshall's Algorithm
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int ct=0;
int graph[MAX][MAX];

void warshall(int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (graph[i][k] == 1)
                for (int j = 1; j <= n; j++)
                {
                    
                    graph[i][j] = (graph[i][j] || graph[k][j]);
                    ct++;
                }
        }
    }
}

void main()
{
    int n, i, j;
    printf("\nEnter the number of vertices:\n");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    warshall(n);

    printf("\nTransitive closure matrix is:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }
    printf("The count for the matrix of %d vertices is %d\n",n,ct);
}

/*output:-
Enter the number of vertices:
4

Enter the adjacency matrix:
0 1 0 0
0 0 0 1
0 0 0 0 
1 0 1 0

Transitive closure matrix is:
1  1  1  1  
1  1  1  1  
0  0  0  0  
1  1  1  1  
The count for the matrix of 4 vertices is 28
*/
