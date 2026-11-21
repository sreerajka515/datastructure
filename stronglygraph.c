#include <stdio.h>

int graph[10][10], transpose[10][10];
int visited[10], stack[10];
int top = -1, n;

void DFS1(int v)
{
    visited[v] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && !visited[i])
            DFS1(i);
    }

    stack[++top] = v;
}

void DFS2(int v)
{
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++)
    {
        if (transpose[v][i] == 1 && !visited[i])
            DFS2(i);
    }
}

int main()
{
    int i, j, count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    // Step 1: Perform DFS and fill stack
    for (i = 0; i < n; i++)
        visited[i] = 0;

    for (i = 0; i < n; i++)
    {
        if (!visited[i])
            DFS1(i);
    }

    // Step 2: Find transpose graph
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            transpose[i][j] = graph[j][i];
        }
    }

    // Step 3: Reset visited array
    for (i = 0; i < n; i++)
        visited[i] = 0;

    // Step 4: Perform DFS in stack order
    printf("\nStrongly Connected Components:\n");

    while (top != -1)
    {
        int v = stack[top--];

        if (!visited[v])
        {
            count++;
            printf("SCC %d: ", count);
            DFS2(v);
            printf("\n");
        }
    }

    return 0;
}

