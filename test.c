/*  ---------------PROBLEM STATEMENT ---------------
    Implement insertion (at the beginning, at the specified location, at the end)
    and deletion (at the beginning, at the specified location, at the end)
    on a single linked list and circular single linked list.
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

Node* insert_at_end(Node *head, int data)
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

int main()
{

    Node *head = (Node *)malloc(sizeof(Node));
    head = NULL;
    int data,choice,position;
    char ch;

    while(1){
        printf("Enter data for node : ");
        scanf("%d",&data);
        head = insert_at_end(head,data);
        printf("Nodes after insertion : ");
        display(head);
        printf("Do you want to insert more nodes (y/n): ");
        scanf(" %c", &ch);
        if(ch == 'y'){
            continue;
        }else if(ch == 'n'){
            printf("Are you sure you doesn't want to insert more nodes (y/n): ");
            scanf(" %c", &ch);
            if(ch == 'y'){
                break;
            }else if (ch == 'n'){
                continue;
            }else{
                printf("Invalid Input\n");
            }
        }else{
            printf("Invalid Input\n");
        }
    }
    printf("\nFinal Linked List : ");
    display(head);
    return 0;
}