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

void create_node(node* head){
    int x;
    char c;
    node* temp = head;
    printf("Enter the value for the node : ");
    scanf("%d", &x);
    head->info = x;

    printf("Do you want to add more nodes : If yes then type 'y' else type 'n' : ");
    // while ((c = getchar()) != '\n' && c != EOF);
    scanf(" %c", &c); // Use a space before %c to skip leading whitespace
    
    if(c == 'y' || c == 'Y'){
        temp = (node*)malloc(sizeof(node));
        head->next = temp;
        create_node(temp);
    }
    else{
        head->next = NULL;
    }
    // else{
    //     printf("\n\n*******Please enter a valid input type!!*******\n\n");
    //     while ((c = getchar()) != '\n' && c != EOF);
    // }

}

void insert_at_begin(node* head, int data){
    // if(head->next == NULL){
    //     create_node(head);
    // }
    node* temp = head;
    temp = (node*)malloc(sizeof(node));
    temp->next = head;
    temp->info = data;
    head = temp;
    printf("Link list after insertion at begin \n");
    // display(head);
}

void insert_at_end(node* head){

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
    insert_at_begin(head,3);
    int choice, data, position;
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