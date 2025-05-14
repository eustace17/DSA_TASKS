#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    // Traverse the list
    while (current != NULL) {
        next = current->next;    // Save next node so as not to lose it
        current->next = prev;    // Reverse the link
        prev = current;          // Move prev forward
        current = next;          // Move current forward
    }

    // When traversal is finished , prev will be the new head so:
    return prev;
}

// create a new node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

//print the list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d → ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Testing if it works
int main() {
    // Creating the list: 1 → 2 → 3 → 4 → NULL
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    printf("Original List:\n");
    printList(head);

    // Reverse the list
    head = reverseList(head);

    printf("\nReversed List:\n");
    printList(head);

    return 0;
}
