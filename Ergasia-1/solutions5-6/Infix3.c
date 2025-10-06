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
    char InfixString[20];

    void InterpretInfix(void) {
        float LeftOperand,RightOperand,Result;
        char;
        int i;
    InitializeStack(&EvalStack); 
        for (i = 0; i < strlen(InfixString); ++i) {
            
            if (isdigit(InfixString[i])) {  // Check if character is a digit
                Push((float)(InfixString[i] - '0'), &EvalStack);
            }
            else if (InfixString[i] == ')') {
                  Pop(&EvalStack,&RightOperand);
                  Pop(&EvalStack,&Operand);
                  Pop(&EvalStack,&RightOperand);
                  switch (Operand) {
                    case '+': Push(LeftOperand + RightOperand, &EvalStack); break;
                    case '-': Push(LeftOperand - RightOperand, &EvalStack); break;
                    case '*': Push(LeftOperand * RightOperand, &EvalStack); break;
                    case '/': Push(LeftOperand / RightOperand, &EvalStack); break;
                    case '^': Push(pow(LeftOperand, RightOperand), &EvalStack); break;
                    default: break;
                  }
                    Push((float)(InfixString[i] - '0'), &EvalStack);
                }
            }
        Pop(&EvalStack, &Result);
        printf("Value of postfix expression = %f\n", Result);
    }
   
    main(int argc, char *argv[]) {
        char *a = argv[1];
        int i, N = strlen(a);
        STACKinit(N);
        for (i = 0; i < N; i++) {
            if (a[i] == ')')  printf("%c ", Pop());        
            if ((a[i] == '+')  ||  (a[i] == '*' || a[i] == '/' || a[i] == '-'))   Push(a[i]);
            if ((a[i] >= '0')  && (a[i] <= '9'))  printf("%c ", a[i]); 
        }
        printf("\n");  
    }
       