// Knapsac problem using memory function
#include <stdio.h>
int value[100], weight[100];
int knap[100][100];
int cnt=0;

int maximum(int a, int b)
{
    int max = (a > b) ? a : b;
    return max;
}

int knapsac(int i, int j)
{
    if (knap[i][j] == -1)
        if (j < weight[i - 1])
            knap[i][j] = knapsac(i - 1, j);
        else
            knap[i][j] = maximum(knapsac(i - 1, j), (value[i - 1] + knapsac(i - 1, j - weight[i - 1])));
    return knap[i][j];
}

void composition(int n, int wt)
{
    int num = 0;
    int subset[n];
    int rc = wt;
    for (int i = n; i >= 1; i--)
    {
        if (knap[i][rc] != knap[i - 1][rc])
        {
            subset[num++] = i;
            rc -= weight[i - 1];
        }
        if (rc == 0)
            break;
    }
    printf("Composition is : ");
    for (int i = 0; i < num; i++)
        printf("%d ", subset[i]);
    printf("\n");
}

int main()
{
    int n, capacity;
    printf("\nEnter number of items:\n");
    scanf("%d", &n);
    printf("\nEnter the maximum capacity of knapsac:\n");
    scanf("%d", &capacity);
    printf("\nEnter the weight and value of each item:\n");
    printf("Weight Value\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &weight[i], &value[i]);
    }
    int i, j;
    for (i = 0; i < n + 1; i++)
    {
        for (j = 0; j < capacity + 1; j++)
        {
            cnt++;
            if (i == 0 || j == 0)
                knap[i][j] = 0;
            else
                knap[i][j] = -1;
        }
    }
    int sol = knapsac(n, capacity);

    printf("\nThe optimum knapsac value is: %d\n", sol);
    composition(n, capacity);
     printf("The basic operation count the given number of items %d and capacity %d\n is %d\n",n,capacity,cnt);

    return 0;
}
/* OUTPUT:-
Enter number of items:
4

Enter the maximum capacity of knapsac:
5

Enter the weight and value of each item:
Weight Value
2 12
1 10
3 20
2 15

The optimum knapsac value is: 37
Composition is : 4 2 1 
The basic operation count the given number of items 4 and capacity 5
 is 30
 */
