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