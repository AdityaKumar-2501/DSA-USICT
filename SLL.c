#include<stdio.h>
#include<stdlib.h>

struct node {
    int INFO;
    struct node* next;
};

void create(struct node*);
void display(struct node*);

int main() {
    struct node* head;
    head = (struct node*)malloc(sizeof(struct node));
    create(head);
    display(head);
    return 0;
}

void create(struct node* head1) {
    struct node* head2;
    char c;
    int x;
    printf("Enter any value: ");
    scanf("%d", &x);
    head1->INFO = x;
    printf("Want to enter more values (y/n): ");
    scanf(" %c", &c);  // Use a space before %c to skip leading whitespace

    if (c == 'y' || c == 'Y') {
        head2 = (struct node*)malloc(sizeof(struct node));
        head1->next = head2;
        create(head2);
    } else {
        head1->next = NULL;
    }
}

void display(struct node* head1) {
    struct node* head2;
    for (head2 = head1; head2 != NULL; head2 = head2->next) {
        printf("%d ", head2->INFO);
    }
    printf("\n");
}
