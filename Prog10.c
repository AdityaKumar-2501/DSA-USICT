/*  ---------------PROBLEM STATEMENT ---------------
   Implement stacks and queues using a linked list.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int info;
    struct Node *next;
}Node;

void mainMenu();

// For stack
Node* top = NULL;
Node* head = NULL; // for keeping track of Nodes in stack

// For queues
Node* front = NULL;
Node* rear = NULL;

// --------------------------- Queues -------------------------------------
int isEmptyLL() {
  if (front == NULL) return 1;
  return 0;
}

void displayLL(){
    if(isEmptyLL()){
        printf("Queue is empty.\n");
        return;
    }
    Node* temp = front;
    while(temp != NULL){
        printf("%d ",temp->info);
        temp = temp->next;
    }
    printf("\n");
}

void EnqueueLL(){
    int x;
    printf("Enter the data : ");
    scanf(" %d",&x);
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->info = x;
    newNode->next = NULL;

    if(front == NULL){
        front = newNode;
        rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

void DequeueLL(){
    if(front == NULL){
        printf("\nUNDERFLOW!\n");
        return;
    }
    if(front == rear){
        printf("Dequeued Element : %d\n", front->info);
        front = NULL;
        rear = NULL;
        return;
    }
    printf("Dequeued Element : %d\n", front->info);
    Node* temp = front;
    front = front->next;
    free(temp);
}

// --------------------------- Stack -------------------------------------

void showStack(){
    if(top == NULL){
        printf("Stack is empty!\n");
        return;
    }
    Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");

}

void push(){
    int x;
    printf("Enter the data : ");
    scanf("%d", &x);
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->info = x;
    newNode->next = NULL;
    if(top == NULL){
        head = newNode;
        top = newNode;
        return;
    }
    top->next = newNode;
    top = newNode;
}

void pop(){
    if(top == NULL){
        printf("\nUNDERFLOW !\n");
        return;
    }
    if(top == head){
        printf("Poped Element : %d\n", top->info);
        head = NULL;
        top = NULL;
        return;
    }
    Node* temp = head;
    while(temp->next != top){
        temp = temp->next;
    }
    printf("Poped Element : %d\n", top->info);
    temp->next = NULL;
    free(top);
    top = temp;
}

void peep(){
    if(top == NULL){
        printf("Stack is empty!\n");
        return;
    }
    printf("\nElement at Top : %d",top->info);
}

void isEmpty(){
    if(top == NULL){
        printf("\nStack is empty!\n");
    }
    else{
        printf("\nStack is NOT empty!\n");
    }
}


// ------------------------- Menu of the Stack ---------------------------
void stackMenu(){
    int choice;
    char c;

    while(1){
        printf("\n************* Menu of Stack ****************\n");
        printf("\nPerform operations on the stack:");
        printf("\n1. Push the element\n2. Pop the element\n3. Show top element\n4. Check if stack is empty\n5. Show all elements of stack\n6. Back to Main Menu\n7. Exit");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                push();
                printf("\nStack after Push operation : ");
                showStack();
                break;
            case 2: 
                pop();
                printf("\nStack after Pop operation : ");
                showStack();
                break;
            case 3:
                peep();
                break;
            case 4:
                isEmpty();
                break;
            case 5:
                printf("Elements in Stack : ");
                showStack();
                break;
            case 6:
                printf("Are you sure you want to go back to Main Menu?\n**** Remember you'll lost all your data **** (y/n): ");
                scanf(" %c", &c);
                if (c == 'y')
                    mainMenu();
                else if (c == 'n')
                    continue;
                else
                    printf("\nInvalid Input!\n");
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

// ------------------------------ Menu of the queue ------------------------------

void QueueMenu(){
    int choice;
    char c;

    while(1){
        printf("\n************* Menu of Queue ****************\n");
        printf("\nPerform operations on the Queue:");
        printf("\n1. Enqueue the element\n2. Dequeue the element\n3. Check if Queue is empty\n4. Show all elements of Queue\n5. Back to Main Menu\n6. Exit");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                EnqueueLL();
                printf("\nCircular Queue after Enqueue : ");
                displayLL();
                break;
            case 2: 
                DequeueLL();
                printf("\nCircular Queue after Dequeue : ");
                displayLL();
                break;
            case 3:
                if(isEmptyLL()){
                    printf("Queue is empty\n");
                }
                else{
                    printf("Queue is not empty\n");
                }
                break;
            case 4:
                printf("Elements in Circular Queue : ");
                displayLL();
                break;
            case 5:
                printf("Are you sure you want to go back to Main Menu?\n**** Remember you'll lost all your data **** (y/n): ");
                scanf(" %c", &c);
                if (c == 'y')
                    mainMenu();
                else if (c == 'n')
                    continue;
                else
                    printf("\nInvalid Input!\n");
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

void mainMenu(){
    int choice;
    char c;

    while(1){
        printf("\n************* MAIN MENU ****************\n");
        printf("\nChoose the Data Structure you want to work on:");
        printf("\n1. Stack\n2. Queue\n3. Exit");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                stackMenu();
                break;
            case 2:
                QueueMenu();
                break;
            case 3:
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