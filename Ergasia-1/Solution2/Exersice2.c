#include <stdio.h>
#include <stdlib.h>
#define max 10


    typedef struct Nodetag {
            int number;
            struct Nodetag *previousn;
            struct Nodetag *nextn;
    }nodetype;
    typedef nodetype *nodepointer;
    struct {
        nodepointer *tail;
        nodepointer *head;
    }headtail;


    nodetype  *Create(headtail *ht) {
        
        ht->head = (nodetype *) malloc(sizeof(nodetype));
        ht->tail = (nodetype *) malloc(sizeof(nodetype));
        
        if (ht->head == NULL || ht->tail == NULL) {
            printf("no memory available\n");
            exit(1);
        }
        ht->head->number = NULL;
        ht->tail->nextn = NULL;
        ht->tail->previousn = NULL;

    }
    nodetype Size(headtail *ht) {
        nodetype *N;
        N = ht->head;
        static int count;
        while (N != NULL) {
            count++;
            N = N->nextn;
        }
        return count;
    }

    nodetype IsEmpty(headtail *ht) {
        
        if (ht->head == NULL) 
          return 1;
        else 
          return 0;
    }

    nodetype GetFirst(headtail *ht) {
        return (ht->head->number);
    }
    nodetype GetLast(headtail *ht) {
            return (ht->tail->number);
    }