#include <stdio.h>
#include <stdlib.h>
#include "Max.h"

    typedef struct Maxtag {
        struct Maxtag *link;
        int number;
    } max;
    max *insert(max *l,int i);
    int findmax(max *l);

   

    int findmax(max *l) {
        static max *n = NULL;
            if (n == NULL) {
                n = (max*)malloc(sizeof(max));
                if (n == NULL) {
                    printf("no mem available\n");
                    return 1;
                }
                n->number = 0;
            }
            if (l == NULL) {
                printf("null list\n");
                return 1;
            }
            if (l->link == NULL) {   /*i am searching all the list until reaching the end*/
                if (l->number > n->number) { /*and every time that i foun bigger element from the previous bigger n */
                    n->number = l->number; /*change n and keep on*/
                    return n->number;
                }
            }
            else {
                if (l->number >n->number)   
                    n->number = l->number;
                return findmax(l->link);
            }
        }
        max *insert(max *l,int i) {
            max *new = (max*) malloc(sizeof(max));
            if (new == NULL) {
                printf("no mem\n");
                return l;
            }
            new->number = i;
            new->link = l;
            return new;
        }

