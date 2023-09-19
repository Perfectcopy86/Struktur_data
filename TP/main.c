#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 26

// adjacency matrix to represent the graph
// a value of 1 indicates a direct edge between two nodes
// a value of 0 indicates no edge between two nodes
int graph[MAX_NODES][MAX_NODES];

// visited array to track which nodes have been visited during the search
bool visited[MAX_NODES];

// array to store the path taken during the search
char path[MAX_NODES];
int pathIndex = 0;

// function to find all paths from a given start node to a given end node
void findPaths(int start, int end, int weight)
{
    // mark the current node as visited
    visited[start] = true;

    // add the current node to the path
    path[pathIndex] = 'A' + start;
    pathIndex++;

    // if the current node is the end node, print the path and total weight
    if (start == end)
    {
        printf("Path: ");
        for (int i = 0; i < pathIndex; i++)
        {
            printf("%c ", path[i]);
        }
        printf("\nTotal weight: %d\n", weight);
    }
    else
    {
        // if the current node is not the end node,
        // recursively search the adjacent nodes
        for (int i = 0; i < MAX_NODES; i++)
        {
            if (graph[start][i] == 1 && !visited[i])
            {
                // add the weight of the edge to the total weight
                findPaths(i, end, weight + graph[start][i]);
            }
        }
    }

    // backtrack by marking the current node as unvisited
    // and removing it from the path
    visited[start] = false;
    pathIndex--;
}

int main()
{
    // initialize the graph with some edges and weights
    graph[0][1] = 1;
    graph[0][2] = 3;
    graph[1][2] = 2;
    graph[1][3] = 4;
    graph[3][4] = 5;
    graph[4][2] = 1;

    // find all paths from node A (0) to node E (4)
    findPaths(0, 4, 0);

    return 0;
}
