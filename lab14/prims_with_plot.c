#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    srand(time(NULL));
    FILE *fp;
    fp = fopen("prims.dat", "w");
    int i, j, edges = 0, c = 0; // Initialize 'c' to 0
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

    while (edges < n - 1)
    {
        min = 9999;
        c++;
        for (i = 0; i < n; i++)
        {
            c++; // Move this line inside the inner loop
            if (visited[i])
            {
                for (j = 0; j < n; j++)
                {
                    if (min > cost[i][j] && !visited[j])
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        printf("%c --> %c | Cost: %d\n", a + 65, b + 65, min);
        visited[b] = 1;
        min_cost += min;
        edges++;
    }

    printf("Minimum Cost: %d\n", min_cost);
    printf("The count for the %d number of vertices is %d\n", n, c);

    fprintf(fp, "%d\t%d\n", n, c);
    fclose(fp);
}
/*output
Enter the number of vertices: 5
Enter cost matrix:
0 0 3 0 0
0 0 10 4 0
3 10 0 2 6
0 4 2 0 1
0 0 6 1 0
A --> C | Cost: 3
C --> D | Cost: 2
D --> E | Cost: 1
D --> B | Cost: 4
Minimum Cost: 10
The count for the 5 number of vertices is 24
*/
