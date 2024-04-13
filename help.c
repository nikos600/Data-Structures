#include <stdio.h>
#include <stdlib.h>

// Define the structure for stack node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to check if the stack is empty
int isEmpty(struct Node* root) {
    return !root;
}

// Function to push an element onto the stack
void push(struct Node** root, int data) {
    struct Node* node = newNode(data);
    node->next = *root;
    *root = node;
    printf("%d pushed to stack.\n", data);
}

// Function to pop an element from the stack
int pop(struct Node** root) {
    if (isEmpty(*root)) {
        printf("Stack underflow.\n");
        return -1;
    }
    struct Node* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Function to sort the stack using recursion
void sortStack(struct Node** root) {
    if (!isEmpty(*root)) {
        int temp = pop(root);
        sortStack(root);
        sortedInsert(root, temp);
    }
}

// Function to insert an element into the sorted stack
void sortedInsert(struct Node** root, int data) {
    if (isEmpty(*root) || data > (*root)->data) {
        push(root, data);
    } else {
        int temp = pop(root);
        sortedInsert(root, data);
        push(root, temp);
    }
}

int main() {
    struct Node* root = NULL;

    push(&root, 4);
    push(&root, 2);
    push(&root, 7);
    push(&root, 1);
    push(&root, 5);

    printf("Stack before sorting:\n");
    struct Node* current = root;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    sortStack(&root);

    printf("Stack after sorting:\n");
    current = root;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}
