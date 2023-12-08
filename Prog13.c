/*  ---------------PROBLEM STATEMENT ---------------
    Implement traversals on Binary Search Tree (using stacks)
    - (Inorder, Preorder, Postorder)
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct Node
{
    int info;
    struct Node *left;
    struct Node *right;
} Node;

void mainMenu();

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->info = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Inserting New node into the Binary tree.

Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        return root;
    }

    if (data >= root->info)
    {
        root->right = insertNode(root->right, data);
    }
    else if (data < root->info)
    {
        root->left = insertNode(root->left, data);
    }
    return root;
}

Node *findMin(Node *node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

Node *deleteNode(Node *root, int data)
{
    if (root == NULL)
    {
        printf("Node with data %d not found in the tree\n", data);
        return root;
    }

    // Search for the node to be deleted
    if (data < root->info)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->info)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children, get the inorder successor (smallest in the right subtree)
        Node *temp = findMin(root->right);

        // Copy the inorder successor's data to this node
        root->info = temp->info;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->info);
    }

    return root;
}

/*
    ******** Algorithm for preorder traversal ********
    1. intially push NULL onto the stack and set a pointer = root
    and repeat following steps until ptr != NULL.
    (a) Procees down the left most part and process(print) each node on the path.
        If node has right child then push it onto the stack.
        Traversal will ends after each node with no left child is processed.
    *Backtracking
    (b) Pop and assign ptr = top (top of the stack) if ptr != NULL
        then return to step (a) else exit program.
*/
void preorder(Node *root)
{
    // base condition
    if (root == NULL)
    {
        return;
    }

    int top = -1;
    Node *stack[SIZE];   // creating a stack for storing the nodes
    stack[++top] = NULL; // Pushing NULL at the bottom of the stack
    Node *ptr = root;    // making a pointer equal to root node

    while (ptr != NULL)
    {
        printf("%d ", ptr->info);

        // checking if the pointer has rigth child, if so, then push it onto the stack
        if (ptr->right)
        {
            stack[++top] = ptr->right;
        }
        // proceeding to the left part of the node
        if (ptr->left)
        {
            ptr = ptr->left;
        }
        // if node is a leaf node, then pop stack and assign the top to the pointer ptr.
        else
        {
            ptr = stack[top];
            top--;
        }
    }
}

/*
    ******** Algorithm for inorder traversal ********
    1. intially push NULL onto the stack and set a pointer = root
    and repeat following steps until ptr != NULL.
    (a) Procees down the left most part and pushing each node onto the stack.
        Traversal ends after each node with no child is processed.
    *Backtracking
    (b) Pop and processed(print) the node,
        if NULL is poped then exit,
        if Node with right child is poped then assign ptr to the right child of that node
        and return to step (a).
*/
void inorder(Node *root)
{
    // base condition
    if (root == NULL)
    {
        return;
    }
    int top = -1;
    Node *stack[SIZE];   // creating a stack for storing the nodes
    stack[++top] = NULL; // Pushing NULL at the bottom of the stack
    Node *ptr = root;    // making a pointer equal to root node
    Node *temp = root;   // creating a temporary used to store the values of stack
    while (temp != NULL || top != -1)
    {
        while (ptr != NULL)
        {
            stack[++top] = ptr;
            ptr = ptr->left;
        }

        temp = stack[top];

        if (temp == NULL)
            return;
        top--;
        printf("%d ", temp->info);
        if (temp->right)
        {
            ptr = temp->right;
        }
    }
}

/*
    ******** Algorithm for postorder traversal ********
    1. intially push NULL onto the stack and set a pointer = root
    and repeat following steps until ptr != NULL.
    (a) Procees down the left most part and pushing each node onto the stack.
        if the node has right child push (-ve) of the right child onto the stack.
        Traversal ends after each node with no child is processed.
    *Backtracking
    (b) Pop and processed(print) the +ve nodes,
        if NULL is poped then exit,
        if Node with (-ve) Node is poped then assign ptr to the that node
        and return to step (a).
*/
void postorder(Node *root)
{
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }
  
    int top = -1;                  
    struct Node* stack[SIZE];
    struct Node* ptr = root;
    do{
        while(ptr!=NULL){
            if(ptr->right)
                stack[++top] = ptr->right;
            stack[++top] = ptr;
            ptr = ptr->left;
        }
        ptr = stack[top];                                    
        top--;
        if(ptr->right && top>=0 && ptr->right == stack[top]){
            top--;
            stack[++top] = ptr;
            ptr = ptr->right;
        }
        else{
            printf("%d ",ptr->info);
            ptr = NULL;
        }
    }while (top>=0);
}

void mainMenu()
{
    Node *root = NULL;

    int choice;
    char c;
    int data;

    while (1)
    {
        printf("\n************* MAIN MENU ****************\n");
        printf("\nPerform operations on the Binary Tree:");
        printf("\n1. Insert a Node\n2. Delete a Node\n3. Preorder Traversal\n4. Inorder Traversal\n5. Postorder Traversal\n6. Exit");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value you want to Insert : ");
            scanf("%d", &data);
            root = insertNode(root, data);
            break;
        case 2:
            if (root == NULL)
            {
                printf("\n***** Tree has no Nodes *****\n");
                break;
            }
            printf("Enter the value you want to Delete : ");
            scanf("%d", &data);
            root = deleteNode(root, data);
            printf("\nTree after deletion (inorder traversal): ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            if (root == NULL)
            {
                printf("\n***** Tree has no Nodes *****\n");
                break;
            }
            printf("Preorder Traversal : ");
            preorder(root);
            printf("\n");
            break;
        case 4:
            if (root == NULL)
            {
                printf("\n***** Tree has no Nodes *****\n");
                break;
            }
            printf("Inorder Traversal : ");
            inorder(root);
            printf("\n");
            break;
        case 5:
            if (root == NULL)
            {
                printf("\n***** Tree has no Nodes *****\n");
                break;
            }
            printf("Postorder Traversal : ");
            postorder(root);
            printf("\n");
            break;
        case 6:
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

int main()
{

    mainMenu();
    return 0;
}