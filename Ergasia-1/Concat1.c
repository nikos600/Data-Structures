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
    Nodetype *Concat(First *r1,First *r2);
    Nodetype *isEmpty(Nodetype *l1,Nodetype *l2);
    void Sorted(First *h);
    Nodetype *GetPrev(First *h,Nodetype *N);

    First *Concatenation(First *l,First *l1) {   /*in this function i get my 2 lists from main*/
                    /*i sort them*/
        Sorted(l);      /*and i call a new function to concat them*/
        Sorted(l1);
        First *result = (First *)malloc(sizeof(First));
        
        result->headlist = Concat(l,l1);
        return result;
        

    }

    Nodetype *Concat(First *r1,First *r2) {
        Nodetype *N1,*P2,*M3,*node;  
        P2 = r2->headlist;    /*2 nodetype pointers for each list to handle them easier*/
        N1 = r1->headlist;
                                 /* here l3 is my new 3 list*/
        First *l3 = (First*)malloc(sizeof(First));
            
            if (l3 == NULL) {
                printf("mem allocation failed\n");
                return NULL;
            }
            l3->headlist = NULL;
            M3 = NULL;   //M3 pointer to l3 list
            while (N1 && P2) {     /*here compare l and l1 list and put the numbers in ascending order*/
                node =(Nodetype*)malloc(sizeof(Nodetype));  /*and put the number in a new node*/
                if (node == NULL) {
                    printf("mem failed\n");
                    return NULL;
                }
                node->link = NULL;
                if (N1->number < P2->number) {
                    node->number = N1->number;
                    N1 = N1->link;
                }
                else {
                    node->number = P2->number;
                    P2 = P2->link;
                }
                if (M3 == NULL) {  /*here M3 put it to point to l3 when null*/
                    M3 = node;
                    l3->headlist = M3;
                }
                else {       /*and with M3 point node which is the new insertion number*/
                    M3->link = node;
                    M3 = node;
                }
            }
            Nodetype *addlast = isEmpty(N1,P2); /*here check if some list has still numbers left*/
           
                while (addlast != NULL) {
                    node =(Nodetype *)malloc(sizeof(Nodetype));
                    if (node == NULL) {
                        printf("mem failed\n");
                        return NULL;
                    }                     /*if yes continue the same process but now with new pointer addlast*/
                    node->link = NULL;      /*which points to some non-empty list*/
                    node->number = addlast->number;
                    M3->link = node;
                    M3 = node;
                    addlast = addlast->link;
                }
            return l3->headlist;
    }
    Nodetype *isEmpty(Nodetype *l1,Nodetype *l2) {
        if (l1 == NULL && l2 == NULL)  /*here check if both of my lists are both NULL*/
         return NULL;
        else if (l1 == NULL)
            return l2;
        else 
            return l1;        
    }
  


    void Sorted(First *h) {
        if (h->headlist == NULL) {
            printf("list is null\n");
            exit(1);
        }  
            Nodetype *S = h->headlist;
            Nodetype *N = S; 
        
       
        for (S = S->link;S != NULL;S = S->link) {   
                if (N->number > S->number) {      /*here i check previous numb n with the next s*/
                    int flag = S->number;       /*swap them*/
                    S->number = N->number;
                    N->number = flag;
                    Nodetype *Prev = GetPrev(h,N);  /*getting the previous pointer from N node*/

                    while (Prev  != NULL && Prev->number > N->number) { /*and make the same procedure*/
                        int flag = N->number;
                        N->number = Prev->number; /*swap*/
                        Prev->number = flag;
                        N = Prev;
                        Prev = GetPrev(h,N);   /*getting previous and compare with N until it's p = n*/
                    }               /*basically working as the Insertion Sort algorithm for a simple linked list*/
                }
                N = S;      /*here make n to become previous because S in the for loop will go to next node*/
            }
        }
        Nodetype *GetPrev(First *h,Nodetype *N) {
            Nodetype *P = h->headlist;
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
            First l1 = {NULL};
            First *l2;
            insert(&l,3);
            insert(&l,37);
            insert(&l,21);
            insert(&l,77);
            Sorted(&l);
            Print(&l);
            insert(&l1,1);
            insert(&l1,25);
            insert(&l1,20);
            insert(&l1,18);
            insert(&l1,100);
            Sorted(&l1);
            Print(&l1);
            l2 = Concatenation(&l,&l1);
            Print(l2);
            return 0;
        }