// #include<stdio.h>
// #include<stdlib.h>

// struct node {
//     int INFO;
//     struct node* next;
// };

// void create(struct node*);
// void display(struct node*);

// int main() {
//     struct node* head;
//     head = (struct node*)malloc(sizeof(struct node));
//     create(head);
//     display(head);
//     return 0;
// }

// void create(struct node* head1) {
//     struct node* head2;
//     char c;
//     int x;
//     printf("Enter any value: ");
//     scanf("%d", &x);
//     head1->INFO = x;
//     printf("Want to enter more values (y/n): ");
//     scanf(" %c", &c);  // Use a space before %c to skip leading whitespace

//     if (c == 'y' || c == 'Y') {
//         head2 = (struct node*)malloc(sizeof(struct node));
//         head1->next = head2;
//         create(head2);
//     } else {
//         head1->next = NULL;
//     }
// }

// void display(struct node* head1) {
//     struct node* head2;
//     for (head2 = head1; head2 != NULL; head2 = head2->next) {
//         printf("%d ", head2->INFO);
//     }
//     printf("\n");
// }



#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (newNode) {
        newNode->next = *head;
        *head = newNode;
    }
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (newNode) {
        if (*head == NULL) {
            *head = newNode;
        } else {
            Node* current = *head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
}

void insertAtLocation(Node** head, int data, int position) {
    if (position < 0) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 0) {
        insertAtBeginning(head, data);
        return;
    }

    Node* newNode = createNode(data);
    if (newNode) {
        Node* current = *head;
        int currentPosition = 0;
        while (current != NULL && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }

        if (current == NULL) {
            printf("Invalid position.\n");
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}

void deleteAtBeginning(Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

void display(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific location\n");
        printf("4. Delete at the beginning\n");
        printf("5. Delete at the end\n");
        printf("6. Display the list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the position (0-based) to insert at: ");
                scanf("%d", &position);
                insertAtLocation(&head, data, position);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                display(head);
                break;
            case 7:
                // Free memory and exit
                while (head != NULL) {
                    Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
