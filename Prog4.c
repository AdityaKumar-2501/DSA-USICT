/*  ---------------PROBLEM STATEMENT ---------------
    Write a program to count the number of nodes & reverse the single linked list.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int info;
    struct Node *next;
} Node;

void display(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}


Node *insert_at_end(Node *head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->info = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        // If the list is empty, the new node becomes the head.
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // Attach the new node to the last node.
        temp->next = newNode;
    }

    return head;
}

Node* Rev(Node *head){

    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* curr = head;;
    Node* prev = NULL;

    while(curr != NULL){
        Node* save = curr->next;
        curr->next = prev;
        prev = curr;
        curr = save;
    }
    head = prev;
    return head;
}


int main(){
    Node *head = (Node *)malloc(sizeof(Node));
    head = NULL;
    int data;
    char c;

    while (1)
    {
        printf("Insert the data for the linked list : ");
        if(scanf("%d", &data) != 1){
            printf("\n***** Please Enter a integer value ****** \n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }
        head = insert_at_end(head, data);
        printf("Nodes after insertion : ");
        display(head);
        ask:
        printf("Do you want to insert more nodes (y/n) : ");
        scanf(" %c",&c);
        if(c == 'n'){
            break;
        }
        else if(c != 'y'){
            printf("\n***** Please Enter a valid character (y/n) ****** \n");
            goto ask;
        }
    }

    printf("\n**** Reverse of the linked list ******\n");
    head = Rev(head);
    display(head);
    return 0;
}