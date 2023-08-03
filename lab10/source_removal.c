#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
int cnt=0;

int graph[SIZE][SIZE], queue[SIZE], rear = -1, front = 0;

void enqueue(int ele)
{
    queue[++rear] = ele;
    printf("-->%c", ele + 65);
}

int dequeue()
{
    return queue[front++];
}

int isEmpty()
{
  
    if (front > rear)
    {
        front = 0;
        rear = -1;
        return 1;
    }
    return 0;
}

int inDegree(int ind, int n)
{
    int indegree = 0;
    for (int i = 0; i < n; i++){
            
        if (graph[i][ind] == 1){
            indegree++;cnt++;
            }
            }
    return indegree;
}

void topo(int n)
{
    int in[n];

    for (int i = 0; i < n; i++)
    {
        in[i] = inDegree(i, n);
        
        if (in[i] == 0){
            enqueue(i);
            cnt++;
            }
    }

    int completed = 0;

    while (completed < n)
    {

        if (isEmpty())
        {
            printf("Cycle exists as no node with indegree exists\n");
            exit(1);
        }

        int src = dequeue();
        completed++;

        for (int i = 0; i < n; i++)
        {
            if (graph[src][i] == 1)
            {
                graph[src][i] = 0;
                in[i]--;
                
                if (in[i] == 0){
                    enqueue(i);
                    cnt++;
                    
                    }
            }
        }
    }
}

void main()
{
    int n;
    printf("\nEnter the number of nodes in the graph:\n");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    topo(n);
    printf("the basic operation count for the given %d vertces matrix is %d\n",n,cnt);
}
/*Enter the number of nodes in the graph:
10

Enter the adjacency matrix:
0 1 1 0 0 0 1 1 0 0
0 0 1 1 0 0 0 1 1 0
0 0 0 1 1 0 0 0 1 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 1 1 0 0 0 1 1 0 0
0 0 1 1 0 0 0 1 1 0
0 0 0 1 1 0 0 0 1 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
-->A-->F-->B-->G-->C-->H-->D-->E-->I-->Jthe basic operation count for the given 10 vertces matrix is 34
*/
/*
// Enter the number of nodes in the graph:
// 8

// Enter the adjacency matrix:
// 0 0 0 1 0 0 0 0
// 1 0 0 1 0 0 0 0
// 0 0 0 0 0 0 0 0
// 0 0 1 0 1 0 0 0
// 0 0 0 0 0 0 0 0
// 0 0 0 0 1 0 0 0
// 0 0 0 1 0 1 0 0
// 0 0 0 0 0 1 0 0
// -->B-->G-->H-->A-->F-->D-->C-->E
*/
