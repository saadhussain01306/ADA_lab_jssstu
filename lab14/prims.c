#include <stdio.h>

void main()
{
    int i, j, edges = 0;
    int a, b, min, min_cost = 0;
    int cost[50][50], n, visited[50] = {0};

    // Taking graph as input
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 9999;
        }
    }

    // Finding minimum cost
    visited[0] = 1;

    while (edges < n - 1) // in a minimum spanning tree(MST), edges=vertices-1
    {
        min = 9999;
        for (i = 0; i < n; i++) // traversing the list of vertices and searching for src vertices i.e traversed/visited vertices
        {
            if (visited[i]) // checking if the source vertex is visited, as an outgoing edge is possible only when the src vertex is traversed
            {
                for (j = 0; j < n; j++) // finding destination vertex
                {
                    if (min > cost[i][j] && !visited[j]) // ensuring that destination vertex is unvisited else if both src and destination vertices are visited then it'll result in a cycle
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        printf("%c-->%c | Cost: %d\n", a + 65, b + 65, min);
        visited[b] = 1; // marking destination vertex as visited
        min_cost += min;
        edges++;
    }

    printf("Minimum Cost: %d\n", min_cost);
}

/*output
Enter the number of vertices: 5
Enter cost matrix:
0 0 3 0 0
0 0 10 4 0
3 10 0 2 6
0 4 2 0 1
0 0 6 1 0
A-->C | Cost: 3
C-->D | Cost: 2
D-->E | Cost: 1
D-->B | Cost: 4
Minimum Cost: 10
    */
