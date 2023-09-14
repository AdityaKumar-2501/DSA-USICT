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

void create_node(node* head){
    int x;
    char c;
    node* temp = head;
    printf("Enter the value for the node : ");
    scanf("%d", &x);
    head->info = x;

    while(1)
    {    
        printf("Do you want to add more nodes : If yes then type 'y' else type 'n' : ");
        while ((c = getchar()) != '\n' && c != EOF);
        scanf(" %c", &c); // Use a space before %c to skip leading whitespace
        
        if(c == 'y' || c == 'Y'){
            temp = (node*)malloc(sizeof(node));
            head->next = temp;
            create_node(temp);
        }else if(c == 'n' || c == 'N'){
            head->next = NULL;
            break;
        }
        else{
            printf("\n\n*******Please enter a valid input type!!*******\n\n");
        }
    }
}

void insert_at_begin(node* head){

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

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main(){

    node* head = (node*)malloc(sizeof(node));
    create_node(head);
    display(head);
    
    return 0;
}