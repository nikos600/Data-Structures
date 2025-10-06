#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct Stacknodetag {
    struct Stacknodetag *next;
    char symbol;
} Stacknode;

typedef struct Stack{
    Stacknode *link;
} Stack;
Stack operands;
int IsEmpty();
    int priorityops(char operator) {
        if (operator =='+' || operator =='-') return 1;
        if (operator =='*' || operator == '/') return 2;
        return 0;
    }
    char Operator1() {
        if (IsEmpty()) {
            return '\0';
        }
        return operands.link->symbol;
    }
    void InitializeStack(Stack *S) {
        S->link = NULL;
     } 
    int IsEmpty() {
        return operands.link == NULL;
    }
    void Push(char symbol) {
        Stacknode *temp = (Stacknode *)malloc(sizeof(Stacknode));

        if (temp == NULL) {
            printf("No memory available");
            return;
        }
        else {
            temp->symbol = symbol;
            temp->next = operands.link;
            operands.link = temp;  
        }
    }

    char Pop() {
        
        if (IsEmpty()) {
            printf("no mem\n");
            exit(1);
        }
        Stacknode *n = operands.link;
        char symbol1= n->symbol;
        operands.link = n->next;
        free(n);
        return symbol1;
    }

    void InfixtoPostfix(char *a) {
        int N = strlen(a);
        InitializeStack(&operands);
        for (int i = 0; i < N; i++) {
            if (isdigit(a[i])) {
                printf("%c",a[i]);
            }
            else if (a[i] == '(') {
                Push(a[i]);
            }
            else if (a[i] == ')') {
                while(!IsEmpty() && Operator1() != '(') {
                    printf("%c",Pop());
                }
            Pop();
            }

            else if (a[i] == '+' || a[i] =='-' || a[i] == '*' || a[i] == '/') {
                while (!IsEmpty() && priorityops(Operator1()) >= priorityops(a[i])) {
                 printf("%c",Pop());
                }
                Push(a[i]);
                }
    }   
        while (!IsEmpty()) {
            printf("%c",Pop());
        }
        printf("\n");  
    }

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("more arguments \n");
        return 1;
    }
    char *a = argv[1];
    InfixtoPostfix(a);
    return 0;
}
