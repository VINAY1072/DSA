/*Take a complete graph of N nodes. N should be input from the user. Store it using either
Adjecency Matrix or Adjecency List. Edge weights (>0, integer) can be taken as random. Find
out the Minimum spannging tree using Prim's and Kruskal Algorithm.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i, j, k, a, b, u, v, n, edge_num = 1;
int min, Minimum_cost = 0, Array[3000][3000], New[3000];

int Search_mat(int i)
{
    while (New[i])
        i = New[i];
    return i;
}

int Unique(int i, int j)
{
    if (i != j)
    {
        New[j] = i;
        return 1;
    }

    return 0;
}

int Algorithm()
{
    int edge_num = 1, i, j;

    int traversed[30] = {0};

    int Minimum, Min_cost = 0, a, b, x, y;

    traversed[1] = 1;

    while (edge_num < n)
    {
        Minimum = 387;

        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= n; j++)
            {
                if (Array[i][j] < Minimum)
                {
                    if (traversed[i] != 0)
                    {
                        Minimum = Array[i][j];
                        a = x = i;

                        b = y = j;
                    }
                }
            }
        }

        if (traversed[x] == 0 || traversed[y] == 0)
        {
            printf("%d) Edge(%d, %d) = %d\n", edge_num++, a, b, Minimum);

            Min_cost = Min_cost + Minimum;

            traversed[b] = 1;
        }

        Array[a][b] = Array[b][a] = 387;
    }

    return 0;
}

int main()
{
    srand(time(NULL));
    printf("\n");
    printf("\nEnter number of vertices:");
    scanf("%d", &n);
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == j)
            {
                Array[i][j] = 387;
            }
            else
            {
                Array[i][j] = 10 + rand() % 10;
            }
        }
    }
    printf("\nthe adjacency matrix is \n");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
        {
            if (Array[i][j] == 387)
            {
                printf(" 0 ");
            }
            else
            {
                printf(" %d ", Array[i][j]);
            }
        }
    }
    printf("\n------Kruskal's algorithm------\n");
    while (edge_num < n)
    {
        for (i = 0, min = 387; i <= n; i++)
        {
            for (j = 0; j <= n; j++)
            {
                if (Array[i][j] < min)
                {
                    min = Array[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = Search_mat(u);
        v = Search_mat(v);

        if (Unique(u, v))
        {
            printf("%d) Edge (%d,%d) =%d\n", edge_num++, a, b, min);
            Minimum_cost += min;
        }

        Array[a][b] = Array[b][a] = 387;
    }

    printf("\nMinimum cost = %d\n", Minimum_cost);
    printf("------Prims algorithm------\n");
    Algorithm();

    return 0;
}
