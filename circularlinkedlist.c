#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* next;
};

// Function to create the circular linked list from user input
struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newnode;
    int data;

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = head; // Default circular connection
        
        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    temp->next = head; // Complete circular link
    return head;
}

// Insert at the beginning
struct node* insertAtBeginning(struct node* head, int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    
    struct node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
    head = newnode;
    return head;
}

// Insert at the end
struct node* insertAtEnd(struct node* head, int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    
    struct node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

// Insert in the middle at a specific position
struct node* insertAtPosition(struct node* head, int value, int position) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    
    struct node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

// Function to display the circular linked list
void display(struct node* head) {
    struct node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Back to %d)\n", head->data);
}

int main() {
    int n, value, position;

    // Creating the initial list
    printf("Enter the number of initial nodes: ");
    scanf("%d", &n);
    struct node* head = createList(n);
    display(head);

    // Insert at beginning
    printf("\nEnter value to insert at the beginning: ");
    scanf("%d", &value);
    head = insertAtBeginning(head, value);
    display(head);

    // Insert at end
    printf("\nEnter value to insert at the end: ");
    scanf("%d", &value);
    head = insertAtEnd(head, value);
    display(head);

    // Insert at a specific position
    printf("\nEnter position to insert at (starting from 1): ");
    scanf("%d", &position);
    printf("Enter value to insert at position %d: ", position);
    scanf("%d", &value);
    head = insertAtPosition(head, value, position);
    display(head);
    
    return 0;
}