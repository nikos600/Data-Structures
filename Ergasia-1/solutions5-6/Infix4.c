#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include "infix7.h"

typedef struct Stacknodetag {
    struct Stacknodetag *next;
    char symbol;
} Stacknode;

typedef struct Stack{
    Stacknode *link;
} Stack;

Stack operands;
Stack EvalStack;

int IsEmpty(Stack *s);

    int priorityops(char operator) {   //here check the operators for priority for the expression
        if (operator =='+' || operator =='-') return 1;
        if (operator =='*' || operator == '/') return 2;
        return 0;
    }
    char Operator1() {   //from this function i get the last in operator 
        if (IsEmpty(&operands)) {
            return '\0';
        }
        return operands.link->symbol;
    }
    void InitializeStack(Stack *S) {
        S->link = NULL;
     } 
    int IsEmpty(Stack *S) {
        return operands.link == NULL;
    }
    void Push(char symbol) {  //this push function is for the char *InfixtoPostfix(char *a) which has
        Stacknode *temp = (Stacknode *)malloc(sizeof(Stacknode)); //only a char argument
                                     //which works only for char variables
        if (temp == NULL) {
            printf("No memory available");
            return;
        }
        else {                      //and push the operators to a different stack to operands stack
            temp->symbol = symbol;
            temp->next = operands.link;
            operands.link = temp;  
        }
    }
    
    void Push1(float symbol,Stack *S) {  //this push function is for the void InterpretPostfix(char *a)
        Stacknode *temp = (Stacknode *)malloc(sizeof(Stacknode));
                                        //where i have converted char to float before call this push1 function
        if (temp == NULL) {                 //and push them into Stack S
            printf("No memory available"); //tha's why i use two different push functions
            return;
        }
        else {
            temp->symbol = symbol;
            temp->next = S->link;
            S->link = temp;  
        }
    }

    char Pop() {
                    //same process but for a Pop function
        if (IsEmpty(&operands)) { //2 functions one for operators 
            printf("no mem\n");
            exit(1);
        }
        Stacknode *n = operands.link;
        char symbol1= n->symbol;
        operands.link = n->next;
        free(n);
        return symbol1;
    }
    void Pop1(Stack *S,float *operand) {
                             //and here for Stack S 
        if (S->link == NULL) {
            printf("no mem\n");
            exit(1);
        }
        Stacknode *n = S->link;
        *operand = n->symbol;
        S->link = n->next;
        free(n);
        
    }

    char *InfixtoPostfix(char *a) {
        static char output[100];
        int N = strlen(a);
        int index = 0;
        InitializeStack(&operands);

        for (int i = 0; i < N; i++) {
            if (isdigit(a[i])) {
                output[index++] = a[i]; //here every time that it's a digit i put it in an array
            }
            else if (a[i] == '(') {  //put it in the stack
                Push(a[i]);
            }
            else if (a[i] == ')') { 
                while(!IsEmpty(&operands) && Operator1() != '(') { 
                    output[index++] = Pop();  //pop the ')' and all other operators from the stack
                }                           //and add them to output until find the '(' character
            Pop();                          //and after delete the '(' from the stack 
            }

            else if (a[i] == '+' || a[i] =='-' || a[i] == '*' || a[i] == '/') {
                while (!IsEmpty(&operands) && priorityops(Operator1()) >= priorityops(a[i])) {
                    output[index++] = Pop();    //check the priority of the current operator
                }                           //with the operator that's has been added last in the top of the stack
                Push(a[i]);                 //i add the operator in the array with the biggest priority
                }                           //with the push function i just push the new operator to stack
    }   
        while (!IsEmpty(&operands)) {
            output[index++] = Pop();
        }                   //when i finished checking the expression just putting the remaining operators to my array
        output[index] = '\0';
        return output;  
    }

    void InterpretPostfix(char *a) {
        float LeftOperand, RightOperand, Result;
        int i;
    InitializeStack(&EvalStack);
        for (i = 0; i < strlen(a); ++i) {
            if (isdigit(a[i])) {                        
                Push1((float)(a[i] - '0'), &EvalStack); // Convert char to float
            }
            else if (a[i] == '+' || a[i] == '-' || a[i] == '*' ||
                a[i] == '/' || a[i] == '^')  {
                Pop1(&EvalStack, &RightOperand);
                Pop1(&EvalStack, &LeftOperand);
                switch (a[i]) {
                    case '+': Push1(LeftOperand + RightOperand, &EvalStack); break;
                    case '-': Push1(LeftOperand - RightOperand, &EvalStack); break;
                    case '*': Push1(LeftOperand * RightOperand, &EvalStack); break;
                    case '/': Push1(LeftOperand / RightOperand, &EvalStack); break;
                    case '^': Push1(pow(LeftOperand, RightOperand), &EvalStack); break;
                    default: break;
                }
            }
            }
    Pop1(&EvalStack, &Result);
    printf("Value of the infix expression = %f\n", Result);
    }
    
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("more arguments \n");
        return 1;
    }
    char *resultpost = InfixtoPostfix(argv[1]);
    InterpretPostfix(resultpost);
    return 0;
}