//Insertion and traversal in a Circular Linked List

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
}; 

struct node* beginning(struct node* head) {
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = 9;

    if (head == NULL) {
        newnode->next = newnode; // Point to itself if list is empty
        return newnode;
    }

    struct node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    
    temp->next = newnode;
    newnode->next = head;
    return newnode;  // New node becomes the head
}

struct node* ending(struct node* head) {
    struct node* end = malloc(sizeof(struct node));
    end->data = 10;

    if (head == NULL) {
        end->next = end;
        return end;
    }

    struct node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = end;
    end->next = head;
    return head;  // Head remains the same
}

struct node* middle(struct node* head, int position) {
    struct node* middle = malloc(sizeof(struct node));
    middle->data = 60;

    if (head == NULL || position == 1) {
        middle->next = head ? head : middle;
        return middle;
    }

    struct node* temp = head;
    for (int i = 2; i < position && temp->next != head; i++) {
        temp = temp->next;
    }

    middle->next = temp->next;
    temp->next = middle;
    return head;
}

void printList(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct node* temp = head;
    do {
        printf("%d \t", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct node* head = NULL;
    struct node* node1 = malloc(sizeof(struct node));
    struct node* node2 = malloc(sizeof(struct node));
    struct node* node3 = malloc(sizeof(struct node));
    struct node* node4 = malloc(sizeof(struct node));

    head = node1;
    node1->data = 5;
    node1->next = node2;

    node2->data = 6;
    node2->next = node3;

    node3->data = 7;
    node3->next = node4;

    node4->data = 8;
    node4->next = head;

    printf("\nThe original List before any operations:\n");
    printList(head);

    head = beginning(head);
    printf("\nThe List after adding a new node at the beginning:\n");
    printList(head);

    head = ending(head);
    printf("\nThe List after adding another node at the end:\n");
    printList(head);

    head = middle(head, 4);
    printf("\nThe List after adding a new node in the 4th place:\n");
    printList(head);

    return 0;
}
