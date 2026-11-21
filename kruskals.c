#include <stdio.h>

int parent[10];

int find(int i)
{
    while(parent[i] != i)
        i = parent[i];

    return i;
}

void union_set(int i, int j)
{
    int a = find(i);
    int b = find(j);

    parent[a] = b;
}

int main()
{
    int cost[10][10];
    int n, i, j, min;
    int u, v, a, b;
    int ne = 1, mincost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    for(i = 1; i <= n; i++)
        parent[i] = i;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while(ne < n)
    {
        min = 999;

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        a = find(u);
        b = find(v);

        if(a != b)
        {
            printf("%d -> %d = %d\n", u, v, min);

            mincost = mincost + min;

            union_set(u, v);

            ne++;
        }

        cost[u][v] = 999;
        cost[v][u] = 999;
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}

