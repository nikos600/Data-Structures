#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h> // Added for malloc

typedef struct Stacknodetag {
    struct Stacknodetag *next;
    char symbol;
} Stacknode;

typedef struct Stack {
    Stacknode *link;
} Stack;

Stack operands;

int IsEmpty(); // Added forward declaration

int priorityops(char operator) {
    if (operator == '+' || operator == '-') return 1;
    if (operator == '*' || operator == '/') return 2;
    return 0;
}
char Operator1() {
    if (IsEmpty()) {
        return '\0'; // Changed NULL to '\0'
    }
    return operands.link->symbol; // Changed data to symbol
}

void InitializeStack(Stack *S) {
    S->link = NULL; // Changed operands->link to S->link
}

int IsEmpty() { // Changed void to int
    return operands.link == NULL;
}

void Push(char symbol) {
    Stacknode *temp = (Stacknode *)malloc(sizeof(Stacknode));
    if (temp == NULL) {
        printf("No memory available");
        return;
    } else {
        temp->symbol = symbol;
        temp->next = operands.link;
        operands.link = temp;
    }
}

char Pop() {
    if (IsEmpty()) {
        printf("Stack is empty\n"); // Changed message
        exit(1);
    }
    Stacknode *n = operands.link;
    char symbol1 = n->symbol;
    operands.link = n->next;
    free(n);
    return symbol1;
}

void InfixtoPostfix(char *a) {
    int N = strlen(a);
    InitializeStack(&operands); // Changed STACKinit to InitializeStack
    for (int i = 0; i < N; i++) { // Added int declaration for i
        if (isdigit(a[i])) {
            printf("%c ", a[i]); // Changed %d to %c
        } else if (a[i] == '(') {
            Push(a[i]); // Changed push to Push
        } else if (a[i] == ')') {
            while (!IsEmpty() && Operator1() != '(') { // Changed Top to Operator1
                printf("%c ", Pop());
            }
            Pop();
        } else if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/') {
            while (!IsEmpty() && priorityops(Operator1()) >= priorityops(a[i])) { // Changed precedece to priorityops
                printf("%c", Pop());
            }
            Push(a[i]); // Changed Push(a[i], &EvalStack) to Push(a[i])
        }
    }
    while (!IsEmpty()) {
        printf("%c", Pop());
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) { // Added argument check
        printf("Usage: %s <expression>\n", argv[0]);
        return 1;
    }
    char *a = argv[1];
    InfixtoPostfix(a);
    return 0; // Added return statement
}