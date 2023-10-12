/*  ---------------PROBLEM STATEMENT ---------------
    Implement a circular queue using arrays and linked list.
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

// display of queue using array need to fix.

void mainMenu();
// ----------------------- Queue using Array ------------------------------

int cir_queue[SIZE];
int front = -1;
int rear = -1;

int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}

int isEmpty() {
  if (front == -1) return 1;
  return 0;
}

void display(){
    if(isEmpty()){
        printf("Queue is empty.\n");
    }
    else{
        for(int i = front; i !=  rear; i = (i + 1) % SIZE){
            printf("%d ", cir_queue[i]);
        }
    }
}

void Enqueue(){
    int x;
    printf("Enter the data : ");
    scanf("%d",&x);
    if(isEmpty()){
        front++;
    }
    else if(isFull()){
        printf("\nOVERFLOW!!\n");
        return;
    }
    rear = (rear + 1) % SIZE;
    cir_queue[rear] = x;
}

void Dequeue(){
    if(front == -1){
        printf("\nUNDERFLOW!!\n");
        return;
    }
    if(front == rear){
        printf("Dequeued Element : %d\n", cir_queue[front]);
        front = -1;
        rear = -1;
    }
    else{
        printf("Dequeued Element : %d\n", cir_queue[front]);
        front++;
    }
}

// ----------------------- Queue using Linked List ------------------------------

typedef struct Node{
    int info;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;


int isEmptyLL() {
  if (head == NULL) return 1;
  return 0;
}

void displayLL(){
    if(isEmptyLL()){
        printf("Queue is empty.\n");
        return;
    }
    Node* temp = head;
    do{
        printf("%d ", temp->info);
        temp= temp->next;
    }while(temp !=head);
}

void EnqueueLL(){
    int x;
    printf("Enter the data : ");
    scanf("%d",&x);
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->info = x;

    if(isEmpty()){
        head = newNode;
        tail = newNode;
    }
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
}

void DequeueLL(){
    if(head == NULL){
        printf("\nUNDERFLOW!\n");
        return;
    }
    if(head == tail){
        printf("Dequeued Element : %d\n", head->info);
        head = NULL;
        tail = NULL;
    }
    Node* temp = head;
    head = head->next;
    tail->next = head;
    free(temp);
}

// ------------------------------ Menu of the queue using Array ------------------------------
void Queue_Array(){
    int choice;
    char c;

    while(1){
        printf("\n************* Circular Queue using Array ****************\n");
        printf("\nPerform operations on the Circular Queue:");
        printf("\n1. Enqueue the element\n2. Dequeue the element\n3. Check if Queue is empty\n4. Check if Queue is Full\n5. Show all elements of Queue\n6. Back to Main Menu\n7. Exit");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                Enqueue();
                printf("\nCircular Queue after Enqueue : ");
                display();
                break;
            case 2: 
                Dequeue();
                printf("\nCircular Queue after Dequeue : ");
                display();
                break;
            case 3:
                if(isEmpty()){
                    printf("Queue is empty\n");
                }
                else{
                    printf("Queue is not empty\n");
                }
                break;
            case 4:
                if(isFull()){
                    printf("Queue is Full\n");
                }
                else{
                    printf("Queue is not Full\n");
                }
                break;
            case 5:
                printf("Elements in Circular Queue : ");
                display();
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

// ------------------------------ Menu of the queue using Linked List ------------------------------

void Queue_LL(){
    int choice;
    char c;

    while(1){
        printf("\n************* Circular Queue using Linked List ****************\n");
        printf("\nPerform operations on the Circular Queue:");
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
        printf("\nChoose type of Queue:");
        printf("\n1. Queue implemented using Array\n2. Queue implemented using Linked List\n3. Exit");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                Queue_Array();
                break;
            case 2:
                Queue_LL();
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