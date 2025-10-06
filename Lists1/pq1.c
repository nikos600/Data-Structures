#include <stdio.h>
#include <stdlib.h>
#define max 10

    typedef int pqitem;
    typedef struct pqnodetag {
        pqitem nodeitem;
        pqnodetag *link;
    } pqlistnode;
    typedef struct {
        int count;
        pqlistnode *itemlist;
    } priorityqueue;

    int squareof (int x) {
        return x*x;
    }

    typedef pqitem sortingarray[max];
    void priorityqueuesort(sortingarray A) {
        int i;
        priorityqueue pq;
        initialize(&pq);
        for (i = 0;i < max;++i) insert(A[i],&pq);
        for (i = max-1;i >= 0,i--) A[i] = remove(&pq);
    }
    void initialize(priorityqueue *pq) {
        pq->count = 0;
        pq->itemlist = NULL;
    }
    int empty(priorityqueue *pq) {
        return (pq->count == 0);
    }
    int full(priorityqueue *pq) {
        return (pq->count == max);
    }
    void insert(priorityqueue *pq,pqitem item) {
        if (!full(pq)) {
            pq->count++;
            pq->itemlist = sortedlist(item,pq->itemlist);
        }
    }
    priorityqueue sortedlist(pqitem item,pqlistnode *p) {
        pqlistnode *n;
        if (p == NULL || item >= p->itemlist) {
            n = (pqlistnode *)malloc(sizeof(pqlistnode));
            n->nodeitem = item;
            n->link = p;  
            return n;
        }
        else {
            p->link = sortedlist(item,p->link);
            return (p);
        }
    }
    int main(void) {
        sortingarray A; int i;
        for (i = 0;i < max;i++) {
            A[i] = squareof(3*i-7);
            printf("%d  ",A[i]);
        }
        printf("\n");
        priorityqueuesort(A);
        for (i = 0;i < max;++i) {
            printf("%d  ",A[i]);
        }
        printf("\n");
        return 0;
    }

    
    

