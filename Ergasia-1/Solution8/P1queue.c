#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p1queue.h"

typedef int Pqitem; 
typedef struct queue {
    int number;
    struct queue *link;
} *qpointnode;     //information hiding with handles 
typedef struct headtail {
    qpointnode head;
    qpointnode tail;
} *queueht; //information hiding with handles 



qpointnode New(Pqitem item) {
        qpointnode x = malloc(sizeof(struct queue));
        if (x == NULL) {
            printf("mem alloc failed\n");
            return NULL;
        }
        x->number = item;
        x->link = NULL;
        return x;
    }

    queueht Queueinit()  {
    
        queueht q = malloc(sizeof *q);
        if (q == NULL) {
            printf("mem alloc failed\n");
            return NULL;
        }    
        q->head = NULL; 
        q->tail = NULL;    
        return q;  
    }
    
    int QUEUEempty(queueht q)  { 
        return q->head == NULL; 
    }

    void QUEUEput(queueht q, Pqitem item) { 
        qpointnode point = New(item);
        if (point == NULL) return;
        if (q->head == NULL) {          
            q->head = point;   
        }    
        else 
            q->tail->link = point; 

        q->tail = point;
    }

    static qpointnode GetPrev(queueht q,qpointnode N) {
        qpointnode P = q->head; // i declare this function as static
        if (P == N) {   //because i used it only in function Sort_Queue 
            return NULL;   //and i hide it from the client from .h file
        }
        while (P->link != N && P->link != NULL) {
            P = P->link;
        }
        return P;

    }

    void Sort_Queue(queueht q) {
        if (q->head == NULL) {
            printf("Queue is empty\n");
            return;
        }
        qpointnode S = q->head;
        qpointnode N = S;
        for (S = S->link;S != NULL;S = S->link) {
            if (N->number > S->number) {      /*here i check previous numb n with the next s*/
                int flag = S->number;       /*swap them*/
                S->number = N->number;
                N->number = flag;
                qpointnode Prev = GetPrev(q,N);
                while (Prev  != NULL && Prev->number > N->number) { /*and make the same procedure*/
                    int flag = N->number;
                    N->number = Prev->number; /*swap*/
                    Prev->number = flag;
                    N = Prev;
                    Prev = GetPrev(q,N);   /*getting previous and compare with N until it's p = n*/
                }               /*basically working as the Insertion Sort algorithm for a simple linked list*/
            }
            N = S;      /*here make n to become previous because S in the for loop will go to next node*/
        }
    }
   
    Pqitem Queueget(queueht q) {    
        if (QUEUEempty(q)) {
            printf("Queue is emnpty\n");
            return 0;
        } 
        Pqitem item = q->head->number;   
        qpointnode t = q->head;
        q->head = q->head->link;    
        free(t);    
        return item;  
    }
    void Print(queueht q) {
        qpointnode pointer = q->head;
        if (pointer == NULL) {
            printf("queue is empty\n");
            return;
        }
        while (pointer != NULL) {
            printf("%d  ",pointer->number);
            pointer = pointer->link;
        }
        printf("\n");
    }


