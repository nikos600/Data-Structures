#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#include "StackInterface1.h" 

typedef struct Stacknodetag {
    struct Stacknodetag *next;
    float symbol;
} Stacknode;

typedef struct Stack {
    Stacknode *link;
} Stack;

void InitializeStack(Stack *S) {
    S->link = NULL;
}

void Push(float symbol, Stack *S) {
    Stacknode *temp = (Stacknode *)malloc(sizeof(Stacknode));

    if (temp == NULL) {
        printf("No memory available\n");
        return;
    } else {
        temp->symbol = symbol;
        temp->next = S->link;
        S->link = temp;
    }
}

void Pop(Stack *S, float *operand) { 
    // Λάθος: Χρησιμοποιούσες "s" στη δήλωση ενώ η παράμετρος είναι "S".
    // Επίσης, δεν πρέπει να γίνει `operand = S->link;` (λάθος τύπου δεδομένων).

    if (S->link == NULL) {  // Έλεγξε αν η στοίβα είναι άδεια
        printf("Stack is empty, cannot pop.\n");
        exit(1);
    }

    Stacknode *n = S->link;
    *operand = n->symbol;  // Αντιγραφή της τιμής του κόμβου στο operand
    S->link = n->next;
    free(n);
}

Stack EvalStack;
char PostfixString[20];

void InterpretPostfix(void) {
    float LeftOperand, RightOperand, Result;
    int i;
    
    InitializeStack(&EvalStack);

    for (i = 0; i < strlen(PostfixString); ++i) {
        if (isdigit(PostfixString[i])) {  
            // Μετατροπή χαρακτήρα σε float
            Push((float)(PostfixString[i] - '0'), &EvalStack);
        } else if (PostfixString[i] == '+' || PostfixString[i] == '-' || 
                   PostfixString[i] == '*' || PostfixString[i] == '/' || 
                   PostfixString[i] == '^') {
            Pop(&EvalStack, &RightOperand);
            Pop(&EvalStack, &LeftOperand);

            switch (PostfixString[i]) {
                case '+': Push(LeftOperand + RightOperand, &EvalStack); break;
                case '-': Push(LeftOperand - RightOperand, &EvalStack); break;
                case '*': Push(LeftOperand * RightOperand, &EvalStack); break;
                case '/': 
                    if (RightOperand == 0) {  
                        // Προστέθηκε έλεγχος για διαίρεση με το μηδέν
                        printf("Error: Division by zero!\n");
                        exit(1);
                    }
                    Push(LeftOperand / RightOperand, &EvalStack); 
                    break;
                case '^': Push(pow(LeftOperand, RightOperand), &EvalStack); break;
                default: break;
            }
        }
    }

    Pop(&EvalStack, &Result);
    printf("Value of postfix expression = %f\n", Result);
}

int main(void) {
    printf("Give input postfix string without blanks: ");
    scanf("%19s", PostfixString);  // Περιορισμός μήκους για αποφυγή υπερχείλισης μνήμης
    InterpretPostfix();
    return 0;
}


