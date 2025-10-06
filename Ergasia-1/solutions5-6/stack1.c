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
    
    typedef struct Stack{
        Stacknode *link;
    } Stack;

    void InitializeStack(Stack *S) {
       S->link = NULL;
    }

    void Push(float symbol,Stack *S) {
        Stacknode *temp = (Stacknode *)malloc(sizeof(Stacknode));

        if (temp == NULL) {
            printf("No memory available");
            return;
        }
        else {
            temp->symbol = symbol;
            temp->next = S->link;
            S->link = temp;  
        }
    }

    void Pop(Stack *S,float *operand) {
        
        if (S->link == NULL) {
            printf("no mem\n");
            exit(1);
        }
        Stacknode *n = S->link;
        *operand = n->symbol;
        S->link = n->next;
        free(n);
        
    }
    Stack EvalStack;

    void InterpretPostfix(char *a) {
        float LeftOperand, RightOperand, Result;
        int i;
    InitializeStack(&EvalStack);
        for (i = 0; i < strlen(a); ++i) {
            if (isdigit(a[i])) {  // Check if character is a digit
                Push((float)(a[i] - '0'), &EvalStack); // Convert char to float
            }
            else if (a[i] == '+' || a[i] == '-' || a[i] == '*' ||
                a[i] == '/' || a[i] == '^')  {
                Pop(&EvalStack, &RightOperand);
                Pop(&EvalStack, &LeftOperand);
                switch (a[i]) {
                    case '+': Push(LeftOperand + RightOperand, &EvalStack); break;
                    case '-': Push(LeftOperand - RightOperand, &EvalStack); break;
                    case '*': Push(LeftOperand * RightOperand, &EvalStack); break;
                    case '/': Push(LeftOperand / RightOperand, &EvalStack); break;
                    case '^': Push(pow(LeftOperand, RightOperand), &EvalStack); break;
                    default: break;
                }
            }
            }
    Pop(&EvalStack, &Result);
    printf("Value of postfix expression = %f\n", Result);
    }
   
    int main(int argc,char *argv[]) {
        if (argc != 2) {
            printf("more arguments\n");
            return 1;
        }
        char *a = argv[1];
        InterpretPostfix(a);
        return 0;
        }

