/*  ---------------PROBLEM STATEMENT ---------------
    Implement graph traversal (DFS & BFS)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function prototypes
void addEdge(int matrix[][MAX_VERTICES], int u, int v, int numVertices);
void displayMatrix(int matrix[][MAX_VERTICES], int numVertices);
void bfs(int matrix[][MAX_VERTICES], int startVertex, int numVertices);
void dfs(int matrix[][MAX_VERTICES], int startVertex, int visited[], int numVertices);

int main() {
    int numVertices, choice, startVertex, u, v;

    printf("Enter the number of vertices (maximum %d): ", MAX_VERTICES);
    scanf("%d", &numVertices);

    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

    // Initialize the matrix with zeros
    for (int i = 0; i < MAX_VERTICES; ++i) {
        for (int j = 0; j < MAX_VERTICES; ++j) {
            adjacencyMatrix[i][j] = 0;
        }
    }
    
    int visited[MAX_VERTICES] = {0};

    do {
        printf("\n************* MAIN MENU ****************\n");
        printf("1. Add Edge\n");
        printf("2. Display Adjacency Matrix\n");
        printf("3. Breadth-First Search (BFS)\n");
        printf("4. Depth-First Search (DFS)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter edge (u v): ");
                scanf("%d %d", &u, &v);
                addEdge(adjacencyMatrix, u, v, numVertices);
                break;
            case 2:
                displayMatrix(adjacencyMatrix, numVertices);
                break;
            case 3:
                printf("Enter starting vertex for BFS: ");
                scanf("%d", &startVertex);
                bfs(adjacencyMatrix, startVertex, numVertices);
                break;
            case 4:
                printf("Enter starting vertex for DFS: ");
                scanf("%d", &startVertex);
                printf("Depth-First Search (DFS): ");
                dfs(adjacencyMatrix, startVertex, visited, numVertices);
                printf("\n");
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add an edge to the adjacency matrix
void addEdge(int matrix[][MAX_VERTICES], int u, int v, int numVertices) {
    if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
        matrix[u][v] = 1;
        matrix[v][u] = 1; // For undirected graph
        printf("Edge (%d, %d) added.\n", u, v);
    } else {
        printf("Invalid vertices. Please enter valid vertices.\n");
    }
}

// Function to display the adjacency matrix
void displayMatrix(int matrix[][MAX_VERTICES], int numVertices) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform Breadth-First Search (BFS)
void bfs(int matrix[][MAX_VERTICES], int startVertex, int numVertices) {
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;
    int visited[MAX_VERTICES] = {0};

    printf("Breadth-First Search (BFS): ");
    printf("%d ", startVertex);
    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front != rear) {
        int currentVertex = queue[++front];
        for (int i = 0; i < numVertices; ++i) {
            if (matrix[currentVertex][i] == 1 && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }

    printf("\n");
}

// Function to perform Depth-First Search (DFS)
void dfs(int matrix[][MAX_VERTICES], int startVertex, int visited[], int numVertices) {
    printf("%d ", startVertex);
    visited[startVertex] = 1;

    for (int i = 0; i < numVertices; ++i) {
        if (matrix[startVertex][i] == 1 && !visited[i]) {
            dfs(matrix, i, visited, numVertices);
        }
    }
}
