/*  ---------------PROBLEM STATEMENT ---------------
    Implement insertion (at the beginning, at the specified location, at the end)
    and deletion (at the beginning, at the specified location, at the end)
    on a double linked list and circular double linked list
*/

/*  @TODO:
    IN circular part
    deletion are pending
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int info;
    struct Node *next;
    struct Node *prev;
} Node;

void mainMenu();

//  ----------------- Doubly Linked List --------------------------------

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

void display_rev(Node *head)
{

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        printf("%d -> ", temp->info);
        temp = temp->prev;
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
        newNode->prev = NULL;
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
        newNode->prev = temp;
    }

    return head;
}

Node *insert_at_begin(Node *head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->info = data;
    newNode->prev = NULL;

    if (head == NULL)
    {
        // If the list is empty, the new node becomes the head.
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    return head;
}

Node *insert_at_location(Node *head, int data, int location)
{
    if (head == NULL)
    {
        printf("\nNode with %d as data is not present in Linked List.\n", location);
        return head;
    }
    Node *temp = head;

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->info = data;

    while (temp != NULL && temp->info != location)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("\nNode with %d as data is not present in Linked List.\n", location);
        free(newNode); // Free the newly allocated node since it's not inserted
    }
    else if (temp->next == NULL)
    {
        head = insert_at_end(head, data);
    }
    else
    {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
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
        head->prev = NULL;
        free(temp);
    }

    return head;
}

Node *delete_at_location(Node *head, int location)
{
    if (head == NULL)
    {
        printf("\nLinked List is empty. Cannot delete.\n");
        return head;
    }

    Node *temp = head;

    // Check if we are deleting the head node
    if (temp->info == location)
    {
        head = delete_at_begin(head);
        return head;
    }

    while (temp != NULL && temp->info != location)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("\nNode with %d as data is not present in Linked List.\n", location);
        return head;
    }
    if (temp->next == NULL)
    {
        head = delete_at_end(head);
        return head;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return head;
}

//  ----------------- Circular Doubly Linked List --------------------------------

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


void display_circular_rev(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *current = head->prev;

    do
    {
        printf("%d -> ", current->info);
        current = current->prev;
    } while (current != head->prev);

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
        newNode->prev = newNode;
        head = newNode;
    }
    else
    {
        Node *last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
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
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    }
    else
    {
        Node *last = head->prev;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
        last->next = newNode;
    }

    return head;
}

Node *insert_at_location_cir(Node *head, int data, int location)
{
    if (head == NULL)
    {
        printf("\nNode with %d as data is not present in Linked List.\n", location);
        return head;
    }
    Node *temp = head;

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->info = data;
    if (temp->info == location)
    {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        return head;
    }

    do
    {
        temp = temp->next;
    } while (temp != head && temp->info != location);
    if (temp == head)
    {
        printf("\nNode with %d as data is not present in Linked List.\n", location);
        free(newNode); // Free the newly allocated node since it's not inserted
    }
    else if (temp->next == head)
    {
        head = insert_at_end_cir(head, data);
    }
    else
    {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
    return head;
}

Node *delete_at_end_cir(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty!!\n");
        return head;
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        Node *last = head->prev;
        last->prev->next = head;
        head->prev = last->prev;
        free(head);
    }

    return head;
}

Node *delete_at_begin_cir(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty!!\n");
        return head;
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        Node *temp = head;
        head->prev->next = temp->next;
        head = temp->next;
        free(temp);
    }

    return head;
}

Node *delete_at_location_cir(Node *head, int location)
{
    if (location < 0)
    {
        printf("\nInvalid Position\n");
        return head;
    }
    else if (location == 0)
    {
        // Delete the first node if location is 0.
        return delete_at_begin_cir(head);
    }

    if (head == NULL)
    {
        printf("List is empty!\n");
        return head;
    }

    int count = 0;
    Node *prev = head;

    do
    {
        if (count == location - 1)
        {
            Node *curr = prev->next;
            prev->next = curr->next;

            if (curr == head)
            {
                printf("Invalid position.\n");
                return head;
            }

            free(curr);
            return head;
        }
        prev = prev->next;
        count++;
    } while (prev->next != head);

    printf("Invalid position.\n");
    return head;
}

//  --------------------- Menu of Doubly Linked List --------------------------------

void MenuOfdll()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head = NULL;
    int choice, data, position;
    char c, position_choice;
    while (1)
    {
        printf("\nDounly Linked List Operations:\n\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific location\n");
        printf("4. Delete at the beginning\n");
        printf("5. Delete at the end\n");
        printf("6. Delete at a specific location\n");
        printf("7. Display the list\n");
        printf("8. Display the list in reverse order\n");
        printf("9. Back to Main Menu\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("\n***** Please Enter a integer value ****** \n");
            while (getchar() != '\n')
                ; // Clear the input buffer
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("Enter data to insert at the beginning: ");
            if (scanf("%d", &data) != 1)
            {
                printf("\n***** Please Enter a integer value ****** \n");
                while (getchar() != '\n')
                    ; // Clear the input buffer
                continue;
            }
            head = insert_at_begin(head, data);
            printf("Nodes after insertion : ");
            display(head);
            break;
        case 2:
            printf("Enter data to insert at the end: ");
            if (scanf("%d", &data) != 1)
            {
                printf("\n***** Please Enter a integer value ****** \n");
                while (getchar() != '\n')
                    ; // Clear the input buffer
                continue;
            }
            head = insert_at_end(head, data);
            printf("Nodes after insertion : ");
            display(head);
            break;
        case 3:
        restart:
            printf("Enter data to insert: ");
            if (scanf("%d", &data) != 1)
            {
                printf("\n***** Please Enter a integer value ****** \n");
                while (getchar() != '\n')
                    ; // Clear the input buffer
                continue;
            }
            printf("Enter the data of existing node which you wish to insert new node after that node : ");
            if (scanf("%d", &position) != 1)
            {
                printf("\n***** Please Enter a integer value ****** \n");
                while (getchar() != '\n')
                    ; // Clear the input buffer
                continue;
            };
            printf("Are you sure you want to insert node after %d (y/n) : ", position);
            scanf(" %c", &position_choice);
            if (position_choice == 'n')
            {
                printf("Renter the data of node where you want to insert new node after it : ");
                if (scanf("%d", &position) != 1)
                {
                    printf("\n***** Please Enter a integer value ****** \n");
                    while (getchar() != '\n')
                        ; // Clear the input buffer
                    continue;
                };
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
            printf("Enter the data of node you wish to delete : ");
            if (scanf("%d", &position) != 1)
            {
                printf("\n***** Please Enter a integer value ****** \n");
                while (getchar() != '\n')
                    ; // Clear the input buffer
                continue;
            }
            printf("Are you sure you want to delete node at %d position (y/n) : ", position);
            scanf(" %c", &position_choice);
            if (position_choice == 'n')
            {
                printf("Renter the data of node you wish to delete : ");
                if (scanf(" %d", &position) != 1)
                {
                    printf("\n***** Please Enter a integer value ****** \n");
                    while (getchar() != '\n')
                        ; // Clear the input buffer
                    continue;
                }
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
            printf("\nDoubly Linked List till now : ");
            display(head);
            break;
        case 8:
            printf("\n Doubly Linked List in reverse order : ");
            display_rev(head);
            break;
        case 9:
            printf("Are you sure you want to go back to Main Menu?\n**** Remember you'll lost all your data **** (y/n): ");
            scanf(" %c", &c);
            if (c == 'y')
                mainMenu();
            else if (c == 'n')
                continue;
            else
                printf("\nInvalid Input!\n");
            break;
        case 10:
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

//  ---------------------- Menu of Circular Doubly Linked List ------------------------------

void MenuOfCll()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head = NULL;
    int choice, data, position;
    char c, position_choice;
    while (1)
    {
        printf("\nCircular Doubly Linked List Operations:\n\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific location\n");
        printf("4. Delete at the beginning\n");
        printf("5. Delete at the end\n");
        printf("6. Delete at a specific location\n");
        printf("7. Display the list\n");
        printf("8. Display the list in reverse order\n");
        printf("9. Back to Main Menu\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("\n***** Please Enter a integer value ****** \n");
            while (getchar() != '\n')
                ; // Clear the input buffer
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("Enter data to insert at the beginning: ");
            if (scanf("%d", &data) != 1)
            {
                printf("\n***** Please Enter a integer value ****** \n");
                while (getchar() != '\n')
                    ; // Clear the input buffer
                continue;
            }
            head = insert_at_begin_cir(head, data);
            printf("Nodes after insertion : ");
            display_circular(head);
            break;
        case 2:
            printf("Enter data to insert at the end: ");
            if (scanf("%d", &data) != 1)
            {
                printf("\n***** Please Enter a integer value ****** \n");
                while (getchar() != '\n')
                    ; // Clear the input buffer
                continue;
            }
            head = insert_at_end_cir(head, data);
            printf("Nodes after insertion : ");
            display_circular(head);
            break;
        case 3:
        restart:
            printf("Enter data to insert: ");
            if (scanf("%d", &data) != 1)
            {
                printf("\n***** Please Enter a integer value ****** \n");
                while (getchar() != '\n')
                    ; // Clear the input buffer
                continue;
            }
            printf("Enter the data of existing node which you wish to insert new node after that node : ");
            if (scanf("%d", &position) != 1)
            {
                printf("\n***** Please Enter a integer value ****** \n");
                while (getchar() != '\n')
                    ; // Clear the input buffer
                continue;
            }
            printf("Are you sure you want to insert node after %d (y/n) : ", position);
            scanf(" %c", &position_choice);
            if (position_choice == 'n')
            {
                printf("Renter the data of node where you want to insert new node after it : ");
                if (scanf(" %d", &position) != 1)
                {
                    printf("\n***** Please Enter a integer value ****** \n");
                    while (getchar() != '\n')
                        ; // Clear the input buffer
                    continue;
                };
            }
            else if (position_choice != 'y')
            {
                printf("Invalid Input\n");
                printf("Starting Again...\n");
                goto restart;
            }
            head = insert_at_location_cir(head, data, position);
            printf("Nodes after insertion : ");
            display_circular(head);
            break;
        case 4:
            head = delete_at_begin_cir(head);
            printf("Nodes after deletion : ");
            display_circular(head);
            break;
        case 5:
            head = delete_at_end_cir(head);
            printf("Nodes after deletion : ");
            display_circular(head);
            break;
        case 6:
        del:
            printf("Enter the position (0-based) to delete node at: ");
            if (scanf("%d", &position) != 1)
            {
                printf("\n***** Please Enter a integer value ****** \n");
                while (getchar() != '\n')
                    ; // Clear the input buffer
                continue;
            }
            printf("Are you sure you want to delete node at %d position (y/n) : ", position);
            scanf(" %c", &position_choice);
            if (position_choice == 'n')
            {
                printf("Renter position of node where you want to delete node : ");
                if (scanf(" %d", &position) != 1)
                {
                    printf("\n***** Please Enter a integer value ****** \n");
                    while (getchar() != '\n')
                        ; // Clear the input buffer
                    continue;
                }
            }
            else if (position_choice != 'y')
            {
                printf("Invalid Input\n");
                printf("Starting Again...\n");
                goto del;
            }
            head = delete_at_location_cir(head, position);
            printf("Nodes after insertion : ");
            display_circular(head);
            break;
        case 7:
            printf("\nCircular doubly Linked List till now : ");
            display_circular(head);
            break;
        case 8:
            printf("\nCircular doubly Linked List in reverse order: ");
            display_circular_rev(head);
            break;
        case 9:
            printf("Are you sure you want to go back to Main Menu?\n**** Remember you'll lost all your data **** (y/n): ");
            scanf(" %c", &c);
            if (c == 'y')
                mainMenu();
            else if (c == 'n')
                continue;
            else
                printf("\nInvalid Input!\n");
            break;
        case 10:
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

        printf("\n================================ Main Menu =============================\n");
        printf("\nSelect type of linked list you want to do operations on :\n");
        printf("1. Doubly Linked List\n");
        printf("2. Circular Doubly Linked List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("\n***** Please Enter a integer value ****** \n");
            while (getchar() != '\n')
                ; // Clear the input buffer
            continue;
        }
        switch (choice)
        {
        case 1:
            MenuOfdll();
            break;
        case 2:
            MenuOfCll();
            break;
        case 3:
            printf("Are you sure you want to exit program? (y/n) : ");
            scanf(" %c", &c);
            if (c == 'y')
            {
                printf("\nExiting the program...\n");
                exit(0);
            }
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
    return 0;
}