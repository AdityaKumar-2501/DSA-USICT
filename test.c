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

Node *insert_at_begin(Node *head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->info = data;

    if (head == NULL)
    {
        // If the list is empty, the new node becomes the head.
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }

    return head;
}

Node *insert_at_location(Node *head, int data,int location)
{
    if(location < 0){
        printf("\nInvalid Position\n");
        return head;
    }
    else if(location == 0){
        head = insert_at_begin(head,data);
        return head;
    }


    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->info = data;

    if (head == NULL)
    {
        if(location > 0){
            printf("\nInvalid Position\n");
            return head;
        }
        // If the list is empty, the new node becomes the head.
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        int count = 0;
        Node *temp = head;
        while (temp != NULL && count < location-1)
        {
            temp = temp->next;
            count++;
        }
        if (temp == NULL) {
            printf("Invalid position.\n");
            return head;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
}

Node *delete_at_end(Node* head)
{
    if (head == NULL)
    {
        printf("List is empty!!\n");
        return head;
    }
    else if(head->next == NULL){
        free(head);
        head = NULL;
    }
    else
    {
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }

    return head;
}

Node *delete_at_begin(Node* head)
{
    if (head == NULL)
    {
        printf("List is empty!!\n");
        return head;
    }
    else if(head->next == NULL){
        free(head);
        head = NULL;
    }
    else
    {
        Node *temp = head;
        head = temp->next;
        free(temp);
    }

    return head;
}


Node *delete_at_location(Node* head, int location)
{
     if(location < 0){
        printf("\nInvalid Position\n");
        return head;
    }
    else if(location == 0){
        head = delete_at_begin(head);
        return head;
    }

    if (head == NULL)
    {
        printf("List is empty!!\n");
        return head;
    }
    else
    {
        int count = 0;
        Node *prev = head;
        while (prev != NULL && count < location-1)
        {
            prev = prev->next;
            count++;
        }
        if (prev == NULL || prev->next == NULL) {
            printf("Invalid position.\n");
            return head;
        }
        Node* curr = prev->next;
        prev->next = curr->next;
        free(curr);
    }

    return head;
}

int main()
{

    Node *head = (Node *)malloc(sizeof(Node));
    head = NULL;
    int data, choice, position;
    char ch,position_choice;

    while (1)
    {
        printf("Enter data for node : ");
        scanf("%d", &data);
        // printf("enter position where node is to be inserted (0-based Indexing): ");
        // scanf("%d", &position);
        // printf("Are you sure you want to insert node at %d position (y/n) : ",position);
        // scanf(" %c", &position_choice);
        // if(position_choice == 'n'){
        //     printf("Renter position of node where you want to insert node : ");
        //     scanf(" %d", &position);
        // }else if (position_choice != 'y')
        // {
        //     printf("Invalid Input\n");
        //     printf("Starting Again...\n");
        //     continue;
        // }
        
        // head = insert_at_begin(head, data);
        head = insert_at_end(head, data);
        // head = insert_at_location(head, data,position);

        printf("Nodes after insertion : ");
        display(head);
        printf("Do you want to insert more nodes (y/n): ");
        scanf(" %c", &ch);
        if (ch == 'y')
        {
            continue;
        }
        else if (ch == 'n')
        {
            printf("Are you sure you doesn't want to insert more nodes (y/n): ");
            scanf(" %c", &ch);
            if (ch == 'y')
            {
                break;
            }
            else if (ch == 'n')
            {
                continue;
            }
            else
            {
                printf("Invalid Input\n");
            }
        }
        else
        {
            printf("Invalid Input\n");
        }
    }
    // head = delete_at_begin(head);
    // display(head);

    // head = delete_at_begin(head);
    // display(head);
    // head = delete_at_begin(head);

    printf("enter position of delete node : ");
    scanf(" %d", &position);
    head = delete_at_location(head,position);
    display(head);

    printf("enter position of delete node : ");
    scanf(" %d", &position);
    head = delete_at_location(head,position);
    display(head);

    printf("enter position of delete node : ");
    scanf(" %d", &position);
    head = delete_at_location(head,position);
    display(head);

    printf("\nFinal Linked List : ");
    display(head);
    return 0;
}