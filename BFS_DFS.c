/*  ---------------PROBLEM STATEMENT ---------------
    Implement graph traversal (DFS & BFS)
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Graph
{
    int numVertices;
    struct Node **adjacencyList;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int numVertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjacencyList = (struct Node **)malloc(numVertices * sizeof(struct Node *));

    // Initialize each adjacency list as empty
    for (int i = 0; i < numVertices; ++i)
    {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

// add edge to src node to dest node.
void addEdge(struct Graph *graph, int src, int dest)
{
    // Add an edge from src to dest
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

void DFS(struct Graph *graph, int vertex, int *visited)
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node *temp = graph->adjacencyList[vertex];
    while (temp != NULL)
    {
        int adjVertex = temp->data;
        if (!visited[adjVertex])
        {
            DFS(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

void BFS(struct Graph *graph, int startVertex)
{
    int *visited = (int *)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; ++i)
    {
        visited[i] = 0;
    }

    int queue[graph->numVertices];
    int front = -1, rear = -1;

    visited[startVertex] = 1;
    printf("%d ", startVertex);
    queue[++rear] = startVertex;

    while (front != rear)
    {
        int currentVertex = queue[++front];
        struct Node *temp = graph->adjacencyList[currentVertex];
        while (temp != NULL)
        {
            int adjVertex = temp->data;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = 1;
                printf("%d ", adjVertex);
                queue[++rear] = adjVertex;
            }
            temp = temp->next;
        }
    }

    free(visited);
}

void mainMenu()
{
    int choice;
    char c,ne;
    int n;
    int s,d;

    while (1)
    {
        printf("\n************* MAIN MENU ****************\n");
        printf("\nEnter number of vertices you want to insert: ");
        scanf("%d", &n);

        struct Graph *graph = createGraph(n);
        int visitedDFS[n];
        // initializing the visited graph with 0
        for(int i = 0; i < n;i++){
            visitedDFS[i] = 0;
        }

        Renter:
        printf("Inserting Edge from source to destination\nNOTE: Give source and destination vertices as integers\n");
        
        while(1){
            printf("Enter src node : ");
            scanf("%d", &s);
            printf("Enter dest node : ");
            scanf("%d", &d);
            // adding new edge from src to dest
            addEdge(graph, s, d);

            printf("Do you want to add more edges(y/n): ");
            scanf(" %c", &ne);
            if(ne == 'n' || ne != 'y'){
                break;
            }
        }
        
        while(1){        
            printf("\n****** Choose any of the following Algorithms ******\n");
            printf("1. Depth-first search (DFS)\n2. Breadth-first search (BFS)\n3. Add more edges\n4. Go to main menu\n5. Exit\n");
            printf("\n\nEnter the choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                printf("Depth-First Search (DFS): ");
                DFS(graph, 0, visitedDFS);
                printf("\n");
                break;
            case 2:
                printf("Breadth-First Search (BFS): ");
                BFS(graph, 0);
                printf("\n");
                break;
            case 3:
                goto Renter;
                break;
            case 4:
                mainMenu();
                break;
            case 5:
                printf("\nAre you sure you want to exit program? (y/n) : ");
                scanf(" %c", &c);
                if (c == 'y')
                    exit(0);
                else if (c != 'n')
                    printf("\nInvalid Input!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
            }
        }
    }
}

int main()
{

    mainMenu();
    // Create a graph with 5 vertices
    // struct Graph* graph = createGraph(7);

    // // Add edges to the graph
    // addEdge(graph, 0, 1);
    // addEdge(graph, 0, 2);
    // addEdge(graph, 1, 3);
    // addEdge(graph, 1, 4);
    // addEdge(graph, 2, 4);
    // addEdge(graph, 3, 9);
    // addEdge(graph, 3, 6);

    // printf("Depth-First Search (DFS): ");
    // int visitedDFS[7] = {0};
    // DFS(graph, 0, visitedDFS);
    // printf("\n");

    // printf("Breadth-First Search (BFS): ");
    // BFS(graph, 0);
    // printf("\n");

    return 0;
}
