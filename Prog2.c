/*  ---------------PROBLEM STATEMENT ---------------
    Implement insertion (at the beginning, at the specified location, at the end)
    and deletion (at the beginning, at the specified location, at the end)
    on a single linked list and circular single linked list.
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node* next;
} node;

void display(node* head){
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

node* create_node(int data){

    node* newnode = (node*) malloc(sizeof(node));
    if(newnode){
        newnode->info = data;
        newnode->next = NULL;
    }
    return newnode;
}

void insert_at_begin(node* head, int data){
    // if(head->next == NULL){
    //     create_node(data);
    // }
    // node* temp = head;
    // temp = (node*)malloc(sizeof(node));
    // temp->next = head;
    // temp->info = data;
    // head = temp;
    // printf("Link list after insertion at begin \n");
    // display(head);
    // node* head = create_node(data);

}

void insert_at_end(node* head,int data){
    node* newNode = create_node(data);
    node* temp = head;
    // if(head == NULL || head->next == NULL){
    //     create_node(data);
    // }
    while(temp != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
}

void insert_at_location(node* head){

}

void delete_at_begin(node* head){

}

void delete_at_end(node* head){

}

void delete_at_location(node* head){

}




int main(){

    node* head = (node*)malloc(sizeof(node));
    // create_node(head);
    // insert_at_begin(head,3);
    int choice, data, position;
    insert_at_begin(head,5);
    insert_at_begin(head,6);
    insert_at_begin(head,7);


    display(head);

    // while (1) {
    //     printf("\nLinked List Operations:\n");
    //     printf("1. Insert at the beginning\n");
    //     printf("2. Insert at the end\n");
    //     printf("3. Insert at a specific location\n");
    //     printf("4. Delete at the beginning\n");
    //     printf("5. Delete at the end\n");
    //     printf("6. Display the list\n");
    //     printf("7. Exit\n");
    //     printf("Enter your choice: ");
    //     scanf("%d", &choice);

    //     switch (choice) {
    //         case 1:
    //             printf("Enter data to insert at the beginning: ");
    //             scanf("%d", &data);
    //             insert_at_begin(head, data);
    //             break;
    //         case 2:
    //             printf("Enter data to insert at the end: ");
    //             scanf("%d", &data);
    //             // insertAtEnd(&head, data);
    //             break;
    //         case 3:
    //             printf("Enter data to insert: ");
    //             scanf("%d", &data);
    //             printf("Enter the position (0-based) to insert at: ");
    //             scanf("%d", &position);
    //             // insertAtLocation(&head, data, position);
    //             break;
    //         case 4:
    //             // deleteAtBeginning(&head);
    //             break;
    //         case 5:
    //             // deleteAtEnd(&head);
    //             break;
    //         case 6:
    //             display(head);
    //             break;
    //         case 7:
    //             // Free memory and exit
    //             while (head != NULL) {
    //                 node* temp = head;
    //                 head = head->next;
    //                 free(temp);
    //             }
    //             exit(0);
    //         default:
    //             printf("Invalid choice. Please try again.\n");
    //     }
    // }
    
    return 0;
}