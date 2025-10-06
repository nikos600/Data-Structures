#include <stdio.h>
#include <stdlib.h>

typedef struct Maxtag {
    struct Maxtag *link;
    int number;
} max;

max *insert(max *l, int i);
int findmax(max *l);

int main(void) {
    max *l = NULL;
    l = insert(l, 10);
    l = insert(l, 15);
    l = insert(l, 20);
    l = insert(l, 5);
    printf("found max numb of list is %d\n", findmax(l));
    return 0;
}

int findmax(max *l) {
   static max *n = NULL;
     if (n == NULL) {
        n =(max*)malloc(sizeof(max));
        if (n == NULL) {
            printf("no mem available\n");
            return 1;
        }
        n->number = 0;
     }
     
     if (l == NULL)  {
         printf("null list\n");
         return 1;
     }

     if (l->link == NULL) {
        if (l->number > n->number) {
            n->number = l->number;
            return n->number;
        }
    }
    else {
        if (l->number > n->number) 
            n->number = l->number;

        return findmax(l->link);
    }
}

max *insert(max *l, int i) {
    max *new = (max *)malloc(sizeof(max));
    if (new == NULL) {
        printf("no mem\n");
        return l;
    }
    new->number = i;
    new->link = l;
    return new;
}
  