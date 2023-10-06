/*  ---------------PROBLEM STATEMENT ---------------
    Implement operations (push, pop) on a stack using arrays.
    Check the status of the stack whether there is underflow or overflow.
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

void showStack(){
    if(top == -1){
        printf("Stack is empty!\n");
        return;
    }
    for(int i = top ; i >=0 ; i--){
        printf("%d ", stack[i]);
    }
}

void push(){
    if(top == SIZE){
        printf("\nOVERFLOW !\n");
        return;
    }
    int x;
    printf("Enter the data : ");
    scanf("%d", &x);
    top = top + 1;
    stack[top] = x;
}

void pop(){
    if(top == -1){
        printf("\nUNDERFLOW !\n");
        return;
    }
    printf("\nPoped element : %d",stack[top]);
    top = top - 1;
}

void peep(){
    if(top == -1){
        printf("Stack is empty!\n");
        return;
    }
    printf("\nElement at Top : %d",stack[top]);
}

void isEmpty(){
    if(top == -1){
        printf("\nStack is empty!\n");
    }
    else{
        printf("\nStack is NOT empty!\n");
    }
}


int main(){

    int choice;
    char c;

    while(1){
        printf("\n************* MAIN MENU ****************\n");
        printf("\nPerform operations on the stack:");
        printf("\n1. Push the element\n2. Pop the element\n3. Show top element\n4. Check if stack is empty\n5. Show all elements of stack\n6. Exit");
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
                printf("Elements in Stack form top to bottom : ");
                showStack();
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