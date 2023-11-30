/*  ---------------PROBLEM STATEMENT ---------------
    Implement operations on Binary Search Tree (Insertion, Deletion, Search,
    Traversals (using recursion)- Inorder, Preorder, Postorder).
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int info;
    struct Node *left;
    struct Node *right;
} Node;

void mainMenu();

// creating a node with a given value

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->info = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Inserting New node into the Binary tree.

Node* insertNode(Node *root, int data){
    if(root == NULL){
        root = createNode(data);
        return root;
    }

    if(data >= root->info){
       root->right =  insertNode(root->right, data);
    }
    else if(data < root->info){
        root->left = insertNode(root->left, data);
    }
    return root;
}

Node* searchNode(Node *root, int data){
    //base case
    if(root == NULL || root->info == data){
        return root;
    }
    if(data >= root->info){
        return searchNode(root->right, data);
    }
    else{
        return searchNode(root->left, data);
    }
}


Node* findMin(Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        printf("Node with data %d not found in the tree\n", data);
        return root;
    }

    // Search for the node to be deleted
    if (data < root->info) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->info) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children, get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);

        // Copy the inorder successor's data to this node
        root->info = temp->info;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->info);
    }

    return root;
}

void preorder(Node* root){
    // base condition
    if(root == NULL){
        return;
    }
    printf("%d ", root->info);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    // base condition
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->info);
    inorder(root->right);
}

void postorder(Node* root){
    // base condition
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->info);
}

void mainMenu(){
    Node* root = NULL;
    
    int choice;
    char c;
    int data;

    while(1){
        printf("\n************* MAIN MENU ****************\n");
        printf("\nPerform operations on the Binary Tree:");
        printf("\n1. Insert a Node\n2. Delete a Node\n3. Search\n4. Preorder Traversal\n5. Inorder Traversal\n6. Postorder Traversal\n7. Exit");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                printf("Enter the value you want to Insert : ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                if(root == NULL){
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
                if(root == NULL){
                    printf("\n***** Tree has no Nodes *****\n");
                    break;
                }
                printf("Enter the value you want to search : ");
                scanf("%d", &data);
                Node * res = NULL;
                res = searchNode(root, data);
                if(res != NULL){
                    printf("\nElement found!\n");
                }
                else{
                    printf("\nNo element found!\n");
                }
                break;
            case 4:
                if(root == NULL){
                    printf("\n***** Tree has no Nodes *****\n");
                    break;
                }
                printf("Preorder Traversal : ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                if(root == NULL){
                    printf("\n***** Tree has no Nodes *****\n");
                    break;
                }
                printf("Inorder Traversal : ");
                inorder(root);
                printf("\n");
                break;
            case 6:
                if(root == NULL){
                    printf("\n***** Tree has no Nodes *****\n");
                    break;
                }
                printf("Postorder Traversal : ");
                postorder(root);
                printf("\n");
                break;
            case 7:
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



int main(){

    mainMenu();

    return 0;
}