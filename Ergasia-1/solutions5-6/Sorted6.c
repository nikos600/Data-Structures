#include <stdio.h>
#include <stdlib.h>

    typedef int sortnumbs;

    typedef struct NodeTag {
        sortnumbs number;
        struct NodeTag *link;
    } Nodetype;
    
    typedef struct {
        Nodetype *headlist;
    } First;
    Nodetype *GetPrev(First *l,Nodetype *N);

    void Sorted(First *l) {
        if (l->headlist == NULL) {
            printf("list is null\n");
            exit(1);
        }
        Nodetype *S = l->headlist;
        Nodetype *N = S;  /*N pointer is S*/

        for (S = S->link;S != NULL;S = S->link) {   
                if (N->number > S->number) {      /*here i check previous numb n with the next s*/
                    int flag = S->number;       /*swap them*/
                    S->number = N->number;
                    N->number = flag;
                    Nodetype *Prev = GetPrev(l,N);  /*getting the previous pointer from N node*/

                    while (Prev  != NULL && Prev->number > N->number) { /*and make the same procedure*/
                        int flag = N->number;
                        N->number = Prev->number; /*swap*/
                        Prev->number = flag;
                        N = Prev;
                        Prev = GetPrev(l,N);   /*getting previous and compare with N until it's p = n*/
                    }               /*basically working as the Insertion Sort algorithm for a simple linked list*/
                }
                N = S;      /*here make n to become previous because S in the for loop will go to next node*/
            }
        }
    Nodetype *GetPrev(First *l,Nodetype *N) {
        Nodetype *P = l->headlist;
        if (P == N) {
            return NULL;
        }
        while (P->link != N && P->link != NULL) {
            P = P->link;
        }
        return P;

    }

    Nodetype *insert(First *l,int i) {
       
        Nodetype *n = (Nodetype *)malloc(sizeof(Nodetype));
        if (n == NULL) {
            printf("Memory alloc failed\n");
            exit(1);
        }
        n->number = i;
        n->link = NULL;
        if (l->headlist == NULL)
            l->headlist = n;
        else {
            n->link = l->headlist;
            l->headlist = n; 
        }

        return n;
    }
    void Print(First *l) {
        Nodetype *f = l->headlist;
        while (f != NULL) {
            printf("%d",f->number);
            if (f->link != NULL) printf(",");
            f = f->link;
            
        } 
        printf("\n");
    }
    int main(void) {
        First l = {NULL};
        insert(&l,3);
        insert(&l,37);
        insert(&l,21);
        insert(&l,77);
        insert(&l,1);
        insert(&l,25);
        insert(&l,20);
        insert(&l,18);
        insert(&l,100);
        Print(&l);
        Sorted(&l);
        Print(&l);
        return 0;
    }