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

void mainMenu();

//  ----------------- Singular Linked List --------------------------------

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

Node *insert_at_location(Node *head, int data, int location)
{
    if (location < 0)
    {
        printf("\nInvalid Position\n");
        return head;
    }
    else if (location == 0)
    {
        head = insert_at_begin(head, data);
        return head;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->info = data;

    if (head == NULL)
    {
        if (location > 0)
        {
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
        while (temp != NULL && count < location - 1)
        {
            temp = temp->next;
            count++;
        }
        if (temp == NULL)
        {
            printf("Invalid position.\n");
            return head;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
}

Node *delete_at_end(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty!!\n");
        return head;
    }
    else if (head->next == NULL)
    {
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

Node *delete_at_begin(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty!!\n");
        return head;
    }
    else if (head->next == NULL)
    {
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

Node *delete_at_location(Node *head, int location)
{
    if (location < 0)
    {
        printf("\nInvalid Position\n");
        return head;
    }
    else if (location == 0)
    {
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
        while (prev != NULL && count < location - 1)
        {
            prev = prev->next;
            count++;
        }
        if (prev == NULL || prev->next == NULL)
        {
            printf("Invalid position.\n");
            return head;
        }
        Node *curr = prev->next;
        prev->next = curr->next;
        free(curr);
    }

    return head;
}

//  ----------------- Circular Singular Linked List --------------------------------

void display_circular(Node *head)
{    
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *current = head;

    do
    {
        printf("%d -> ", current->info);
        current = current->next;
    } while (current != head);

    printf("Head\n");

}

Node *insert_at_begin_cir(Node *head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->info = data;

    if (head == NULL)
    {
        // If the list is empty, the new node becomes the head.
        newNode->next = newNode;
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    return head;
}

Node *insert_at_end_cir(Node *head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->info = data;

    if (head == NULL)
    {
        // If the list is empty, the new node becomes the head.
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        // Attach the new node to the last node.
        temp->next = newNode;
        newNode->next = head;
    }

    return head;
}

Node *insert_at_location_cir(Node *head, int data, int location)
{
    if (location < 0)
    {
        printf("\nInvalid Position\n");
        return head;
    }
    else if (location == 0)
    {
        head = insert_at_begin_cir(head, data);
        return head;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->info = data;

    if (head == NULL)
    {
        if (location > 0)
        {
            printf("\nInvalid Position\n");
            return head;
        }
        // If the list is empty, the new node becomes the head.
        head = newNode;
        newNode->next = head;
    }
    else
    {
        int count = 0;
        Node *temp = head;
        while (temp != head && count < location - 1)
        {
            temp = temp->next;
            count++;
        }
        if (temp == head)
        {
            printf("Invalid position.\n");
            return head;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
}


//  --------------------- Menu of Singular Linked List --------------------------------

void MenuOfSll()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head = NULL;
    int choice, data, position;
    char c, position_choice;
    while (1)
    {
        printf("\nSingular Linked List Operations:\n\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific location\n");
        printf("4. Delete at the beginning\n");
        printf("5. Delete at the end\n");
        printf("6. Delete at a specific location\n");
        printf("7. Display the list\n");
        printf("8. Back to Main Menu\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert at the beginning: ");
            scanf("%d", &data);
            head = insert_at_begin(head, data);
            printf("Nodes after insertion : ");
            display(head);
            break;
        case 2:
            printf("Enter data to insert at the end: ");
            scanf("%d", &data);
            head = insert_at_end(head, data);
            printf("Nodes after insertion : ");
            display(head);
            break;
        case 3:
        restart:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter the position (0-based) to insert at: ");
            scanf("%d", &position);
            printf("Are you sure you want to insert node at %d position (y/n) : ", position);
            scanf(" %c", &position_choice);
            if (position_choice == 'n')
            {
                printf("Renter position of node where you want to insert node : ");
                scanf(" %d", &position);
            }
            else if (position_choice != 'y')
            {
                printf("Invalid Input\n");
                printf("Starting Again...\n");
                goto restart;
            }
            head = insert_at_location(head, data, position);
            printf("Nodes after insertion : ");
            display(head);
            break;
        case 4:
            head = delete_at_begin(head);
            printf("Nodes after deletion : ");
            display(head);
            break;
        case 5:
            head = delete_at_end(head);
            printf("Nodes after deletion : ");
            display(head);
            break;
        case 6:
        del:
            printf("Enter the position (0-based) to delete node at: ");
            scanf("%d", &position);
            printf("Are you sure you want to insert node at %d position (y/n) : ", position);
            scanf(" %c", &position_choice);
            if (position_choice == 'n')
            {
                printf("Renter position of node where you want to delete node : ");
                scanf(" %d", &position);
            }
            else if (position_choice != 'y')
            {
                printf("Invalid Input\n");
                printf("Starting Again...\n");
                goto del;
            }
            head = delete_at_location(head, position);
            printf("Nodes after insertion : ");
            display(head);
            break;
        case 7:
            printf("Linked List till now : ");
            display(head);
            break;
        case 8:
            mainMenu();
            break;
        case 9:
            printf("Are you sure you want to exit program? (y/n) : ");
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

//  ---------------------- Menu of Circular Singular Linked List ------------------------------

void MenuOfCll()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head = NULL;
    int choice, data, position;
    char c, position_choice;
    while (1)
    {
        printf("\nSingular Linked List Operations:\n\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific location\n");
        printf("4. Delete at the beginning\n");
        printf("5. Delete at the end\n");
        printf("6. Delete at a specific location\n");
        printf("7. Display the list\n");
        printf("8. Back to Main Menu\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert at the beginning: ");
            scanf("%d", &data);
            head = insert_at_begin_cir(head, data);
            printf("Nodes after insertion : ");
            display_circular(head);
            break;
        case 2:
            printf("Enter data to insert at the end: ");
            scanf("%d", &data);
            head = insert_at_end_cir(head, data);
            printf("Nodes after insertion : ");
            display_circular(head);
            break;
        case 3:
        restart:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter the position (0-based) to insert at: ");
            scanf("%d", &position);
            printf("Are you sure you want to insert node at %d position (y/n) : ", position);
            scanf(" %c", &position_choice);
            if (position_choice == 'n')
            {
                printf("Renter position of node where you want to insert node : ");
                scanf(" %d", &position);
            }
            else if (position_choice != 'y')
            {
                printf("Invalid Input\n");
                printf("Starting Again...\n");
                goto restart;
            }
            head = insert_at_location(head, data, position);
            printf("Nodes after insertion : ");
            display_circular(head);
            break;
        case 4:
            head = delete_at_begin(head);
            printf("Nodes after deletion : ");
            display_circular(head);
            break;
        case 5:
            head = delete_at_end(head);
            printf("Nodes after deletion : ");
            display_circular(head);
            break;
        case 6:
        del:
            printf("Enter the position (0-based) to delete node at: ");
            scanf("%d", &position);
            printf("Are you sure you want to insert node at %d position (y/n) : ", position);
            scanf(" %c", &position_choice);
            if (position_choice == 'n')
            {
                printf("Renter position of node where you want to delete node : ");
                scanf(" %d", &position);
            }
            else if (position_choice != 'y')
            {
                printf("Invalid Input\n");
                printf("Starting Again...\n");
                goto del;
            }
            head = delete_at_location(head, position);
            printf("Nodes after insertion : ");
            display_circular(head);
            break;
        case 7:
            printf("Linked List till now : ");
            display_circular(head);
            break;
        case 8:
            mainMenu();
            break;
        case 9:
            printf("Are you sure you want to exit program? (y/n) : ");
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

//  --------------------------- Main Menu ------------------------------

void mainMenu()
{

    Node *head = (Node *)malloc(sizeof(Node));
    head = NULL;
    int choice;
    char c;

    while (1)
    {
        printf("\nSelect type of linked list you want to do operations on :\n");
        printf("1. Singular Linked List\n");
        printf("2. Circular Singular Linked List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            MenuOfSll();
            break;
        case 2:
            MenuOfCll();
            break;
        case 3:
            printf("Are you sure you want to exit program? (y/n) : ");
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

int main()
{
    mainMenu();
    // Node *head = (Node *)malloc(sizeof(Node));
    // head = NULL;
    // int data, choice, position;
    // char ch,position_choice;

    // while (1)
    // {
    //     printf("\nSelect type of linked list you want to do operations on :\n");
    //     printf("1. Singular Linked List\n");
    //     printf("2. Circular Singular Linked List\n");
    //     printf("3. Exit\n");
    //     printf("Enter your choice: ");
    //     scanf("%d", &choice);
    //     switch (choice) {
    //         case 1:
    //             MenuOfSll();
    //             break;
    //         case 2:
    //             MenuOfCll();
    //             break;
    //         case 3:
    //             // Free memory and exit
    //             while (head != NULL) {
    //                 Node* temp = head;
    //                 head = head->next;
    //                 free(temp);
    //             }
    //             exit(0);
    //         default:
    //             printf("Invalid choice. Please try again.\n");
    //     }

    //     // printf("Enter data for node : ");
    //     // scanf("%d", &data);
    //     // printf("enter position where node is to be inserted (0-based Indexing): ");
    //     // scanf("%d", &position);
    //     // printf("Are you sure you want to insert node at %d position (y/n) : ",position);
    //     // scanf(" %c", &position_choice);
    //     // if(position_choice == 'n'){
    //     //     printf("Renter position of node where you want to insert node : ");
    //     //     scanf(" %d", &position);
    //     // }else if (position_choice != 'y')
    //     // {
    //     //     printf("Invalid Input\n");
    //     //     printf("Starting Again...\n");
    //     //     continue;
    //     // }

    //     // head = insert_at_begin(head, data);
    //     head = insert_at_end(head, data);
    //     // head = insert_at_location(head, data,position);

    //     printf("Nodes after insertion : ");
    //     display(head);
    //     printf("Do you want to insert more nodes (y/n): ");
    //     scanf(" %c", &ch);
    //     if (ch == 'y')
    //     {
    //         continue;
    //     }
    //     else if (ch == 'n')
    //     {
    //         printf("Are you sure you doesn't want to insert more nodes (y/n): ");
    //         scanf(" %c", &ch);
    //         if (ch == 'y')
    //         {
    //             break;
    //         }
    //         else if (ch == 'n')
    //         {
    //             continue;
    //         }
    //         else
    //         {
    //             printf("Invalid Input\n");
    //         }
    //     }
    //     else
    //     {
    //         printf("Invalid Input\n");
    //     }
    // }
    // // head = delete_at_begin(head);
    // // display(head);

    // // head = delete_at_begin(head);
    // // display(head);
    // // head = delete_at_begin(head);

    // printf("enter position of delete node : ");
    // scanf(" %d", &position);
    // head = delete_at_location(head,position);
    // display(head);

    // printf("enter position of delete node : ");
    // scanf(" %d", &position);
    // head = delete_at_location(head,position);
    // display(head);

    // printf("enter position of delete node : ");
    // scanf(" %d", &position);
    // head = delete_at_location(head,position);
    // display(head);

    // printf("\nFinal Linked List : ");
    // display(head);
    return 0;
}