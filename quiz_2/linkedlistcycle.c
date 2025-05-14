#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for the linked list node I am going to use
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// hasCycle() checks if the linked list has a cycle (loop)
bool hasCycle(Node* head) {
    // If the list is empty there of course cannot be a cycle since no elements
    if (head == NULL) return false;

    // Created 2 pointers the slow one moves one step at a time and the second one moves 2 steps at a time eventually if there is a cycle they will meet
    Node* slow = head;
    Node* fast = head;

    // Loop through the list while fast and fast->next are not NULLs 
    //Is fast still on a valid node? and can fast move forward two steps safely?
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;             // move one step
        fast = fast->next->next;       //move two steps

        // If they ever point to the same node, we found a cycle
        if (slow == fast) {
            return true;
        }
    }

    //But  If fast reaches the end, there's no cycle
    return false;
}

// Function to create a new node 
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

//The Function helps us create a test linked list
// pos = -1 means no cycle, pos = 0 or more means connect tail to that index
Node* createListWithCycle(int vals[], int size, int pos) {
    Node* head = NULL;
    Node* tail = NULL;
    Node* cycleNode = NULL;

    for (int i = 0; i < size; i++) {
        Node* newNode = createNode(vals[i]);
        if (head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }

        tail = newNode;

        // The node at the "pos" index
        if (i == pos) {
            cycleNode = newNode;
        }
    }

    // If pos is not -1, connect the last node to the node at index "pos"
    if (pos != -1 && tail != NULL) {
        tail->next = cycleNode;
    }

    return head;
}

// Main function to test if the hasCycle actuall works withs some example cases(connect tail to a specific position)
int main() {
    // Example 1: Input = [3, 2, 0, -4], pos = 1 (tail connects to index 1)
    int values1[] = {3, 2, 0, -4};
    Node* head1 = createListWithCycle(values1, 4, 1);
    printf("Test Case 1: %s\n", hasCycle(head1) ? "true (has cycle)" : "false (no cycle)");

    // Example 2: Input = [1, 2], pos = 0 (tail connects to index 0)
    int values2[] = {1, 2};
    Node* head2 = createListWithCycle(values2, 2, 0);
    printf("Test Case 2: %s\n", hasCycle(head2) ? "true (has cycle)" : "false (no cycle)");

    // Example 3: Input = [1], pos = -1 (no cycle)
    int values3[] = {1};
    Node* head3 = createListWithCycle(values3, 1, -1);
    printf("Test Case 3: %s\n", hasCycle(head3) ? "true (has cycle)" : "false (no cycle)");

    return 0;
}
