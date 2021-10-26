#include <stdio.h>
#include <stdlib.h>

#define MAX 100

#define initial 1
#define waiting 2
#define visited 3

int n;
int matrix[MAX][MAX];
int state[MAX];
void create_adjacency_matrix();
void bfs();
void BFS(int v);
void DFS(int);
int G[8][8], visited_vertices[8], indeg[8], n;

int queue[MAX], front = -1, back = -1;
void enqueu(int vertex);
int dequeue();
int isEmpty_queue();

void visualize_graph()
{
    printf("\nthe graph that i selected is :-");
    printf("\n    7--1--2--8  ");
    printf("\n          |  ");
    printf("\n          4 ");
    printf("\n          | ");
    printf("\n          6--3 ");
    printf("\n          | ");
    printf("\n          5  ");
}
void adj_matrix()
{
    printf("\n the adjacency list is:\n");

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf(" %d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int indegree(int v)
{
    int i, in_deg = 0;
    for (i = 0; i < n; i++)
        if (matrix[i][v] == 1)
            in_deg++;
    return in_deg;
}

void topo_sort()
{
    int count, topo_order[10];
    for (int i = 0; i < n; i++)
    {
        indeg[i] = indegree(i);
        if (indeg[i] == 0)
            enqueu(i);
    }
    count = 0;
    while (!isEmpty_queue() && count < n)
    {
        int v = dequeue();
        topo_order[++count] = v;
        for (int i = 0; i < n; i++)
        {
            if (matrix[v][i] == 1)
            {
                matrix[v][i] = 0;
                indeg[i] = indeg[i] - 1;
                if (indeg[i] == 0)
                    enqueu(i);
            }
        }
    }
    if (count < n)
    {
        printf("\n graph contains cycle\n");
        exit(1);
    }
    for (int i = 1; i <= count; i++)
        printf(" %d ", topo_order[i] + 1);
    printf("\n");
}

int main()
{
    visualize_graph();
    n = 10;
    matrix[0][1] = 1;
    matrix[0][6] = 1;
    matrix[1][7] = 1;
    matrix[1][3] = 1;
    matrix[3][5] = 1;
    matrix[5][2] = 1;
    matrix[5][4] = 1;
    adj_matrix();
    printf("\nlets take node 1 as the starting point\n");
    printf("\n     --breadth first search         - \n");
    bfs();
    printf("\n     --deapth first search         - \n");
    DFS(0);
    printf("\n     --topological sort         - \n");
    topo_sort();
    return 0;
}

void bfs()
{
    int v;
    for (v = 0; v < n; v++)
        state[v] = initial;
    v = 1;
    BFS(v - 1);
}

void DFS(int i)
{
    int j;
    printf(" %d ", i + 1);
    visited_vertices[i] = 1;

    for (j = 0; j < n; j++)
        if (!visited_vertices[j] && matrix[i][j] == 1)
            DFS(j);
}
void BFS(int v)
{
    int i;
    enqueu(v);
    state[v] = waiting;
    while (!isEmpty_queue())
    {
        v = dequeue();
        printf(" %d ", v + 1);
        state[v] = visited;
        for (i = 0; i < n; i++)
        {
            if (matrix[v][i] == 1 && state[i] == initial)
            {
                enqueu(i);
                state[i] = waiting;
            }
        }
    }
    printf("\n");
}

void enqueu(int vertex)
{
    if (back == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        if (front == -1)
            front = 0;
        back = back + 1;
        queue[back] = vertex;
    }
}

int isEmpty_queue()
{
    if (front == -1 || front > back)
        return 1;
    else
        return 0;
}

int dequeue()
{
    int delete_item;
    if (front == -1 || front > back)
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    delete_item = queue[front];
    front = front + 1;
    return delete_item;
}
