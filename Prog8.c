/*  ---------------PROBLEM STATEMENT ---------------
    Implement operations (enqueue, dequeue) on a queue using arrays.
    Check the status of the queue whether it is empty or full.
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;



int isFull() {
  if (front == 0 && rear == SIZE - 1) return 1;
  return 0;
}

int isEmpty(){
    if(front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

void display(){
    if(isEmpty()){
        printf("Queue is empty.\n");
    }
    else{
        for(int i = front; i <= rear; i++){
            printf("%d ", queue[i]);
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
    else if(rear == SIZE-1){
        printf("\nOVERFLOW!!\n");
        return;
    }
    
    rear++;
    queue[rear] = x;
}

void Dequeue(){
    if(front == -1){
        printf("\nUNDERFLOW!!\n");
        return;
    }
    if(front == rear){
        printf("Dequeued Element : %d\n", queue[front]);
        front = -1;
        rear = -1;
    }
    else{
        printf("Dequeued Element : %d\n", queue[front]);
        front++;
    }
}

int main(){
    int choice;
    char c;

    while(1){
        printf("\n************* MAIN MENU ****************\n");
        printf("\nPerform operations on the Queue:");
        printf("\n1. Enqueue the element\n2. Dequeue the element\n3. Check if Queue is empty\n4. Check if Queue is Full\n5. Show all elements of Queue\n6. Exit");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                Enqueue();
                printf("\nQueue after Enqueue : ");
                display();
                break;
            case 2: 
                Dequeue();
                printf("\nQueue after Dequeue : ");
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
                printf("Elements in Queue : ");
                display();
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
    return 0;
}