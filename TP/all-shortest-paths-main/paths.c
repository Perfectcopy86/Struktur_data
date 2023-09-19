/*
 * Created by Varnion on 27/06/2022.
 *
 * Program to build a directed weighted graph from a cost string,
 * print all path(s) from source to destination,
 * and then print the shortest path (or paths) among them.
 */

// Header files.
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>
#include "paths.h"

// Main function.
int main()
{
    // Ask the user for the number of vertices.
    int v;
    printf("\nNumber of vertices:");
    scanf("%i", &v);

    // Ask the user for the number of edges.
    int e;
    printf("Number of edges:");
    scanf("%i", &e);

    // Ask the user for the cost string.
    int cost;
    printf("\nCost String:");
    scanf("%d", &cost);

    // Create the graph.
    Graph *graph = createGraph(v);

    // Add edges to the graph.
    for (int i = 0, s, d; i < e; i++)
    {
        printf("\n%i° Edge\n", i + 1);
        printf("   Source vertex:");
        scanf("%i", &s);
        printf("   Destination vertex:");
        scanf("%i", &d);

        addEdge(graph, s - 1, d - 1, cost);
    }

    // Ask the user for the source and destination vertices.
    printf("\n");
    int src;
    printf("Path source:");
    scanf("%i", &src);
    int dst;
    printf("Path destination:");
    scanf("%i", &dst);

    // Print all paths from source to destination..
    printf("\nPossible path(s) from %d to %d:\n\t", src, dst);
    search(graph, src - 1, dst - 1);

    // End the program.
    clear(graph);
    return 0;
}

// Create a node.
Node *createNode(int vertex, float weight)
{
    Node *node = malloc(sizeof(Node));
    node->vertex = vertex;
    node->weight = weight;
    node->next = NULL;
    return node;
}

// Create the graph.
Graph *createGraph(int vertices)
{
    Graph *graph = malloc(sizeof(Graph));
    graph->index = graph->path_index = 0;
    graph->distance = 0;
    graph->min = FLT_MAX;
    graph->path = calloc(vertices, sizeof(int));
    graph->paths = calloc(vertices, sizeof(int *));
    for (int i = 0; i < vertices; i++)
    {
        graph->paths[i] = calloc(vertices, sizeof(int));
    }
    graph->path_sizes = calloc(vertices, sizeof(int));
    graph->distances = calloc(vertices, sizeof(int));
    graph->visited = calloc(vertices, sizeof(bool));
    graph->array = calloc(vertices, sizeof(Node *));
    return graph;
}

// Add an edge to the graph.
void addEdge(Graph *graph, int source, int destination, int weight)
{
    Node *node = createNode(destination, weight);
    node->next = graph->array[source];
    graph->array[source] = node;
}

// Find all paths from source to destination.
void search(Graph *graph, int src, int dst)
{
    // Mark the current node and store it in path.
    graph->visited[src] = true;
    graph->path[graph->index] = src;
    graph->index++;

    // If current vertex is same as destination.
    if (src == dst)
    {
        int i;
        for (i = graph->index; i > 0; i--)
        {

            if (i != graph->index - 1)
            {
                printf("%d -> ", graph->path[i] + 1);
            }
            else
            {
                printf("%d = %.3f\n\t", graph->path[i] + 1, graph->distance);
            }
        }
    }
    else
    {
        // For all unvisited vertices adjacent to current vertex.
        for (Node *adj = graph->array[src]; adj; adj = adj->next)
        {
            if (!graph->visited[adj->vertex])
            {
                graph->distance += adj->weight;
                search(graph, adj->vertex, dst);
                graph->index--;
                graph->distance -= adj->weight;
                graph->visited[adj->vertex] = false;
            }
        }
    }
}

// Free the memory allocated to the graph.
void clear(Graph *graph)
{
    for (Node *i = graph->array[0]; i; i = i->next)
    {
        Node *temp = i->next;
        i->next = temp->next;
        free(graph->paths[temp->vertex]);
        free(graph->array[temp->vertex]);
        free(temp);
    }
    free(graph->path);
    free(graph->paths);
    free(graph->path_sizes);
    free(graph->distances);
    free(graph->visited);
    free(graph->array);
    free(graph);
}
