#include <stdio.h>
#include <stdlib.h>
#define max 10


    typedef struct Nodetag {
            int number;
            struct Nodetag *previousn;
            struct Nodetag *nextn;
    }nodetype;
   
    typedef struct {
        nodetype *tail;
        nodetype *head;
    }headtail;
    nodetype Createheadtail(headtail *ht) {
        ht->head = (nodetype *) malloc(sizeof(nodetype));
        ht->tail = (nodetype *) malloc(sizeof(nodetype));
        
        if (ht->head == NULL || ht->tail == NULL) {
            printf("no memory available\n");
            exit(1);
        }
        ht->head->nextn = NULL;
        ht->head->previousn = NULL; 
        ht->tail->nextn = NULL;
        ht->tail->previousn = NULL;
        return (ht->head);
    }

    nodetype *Create(nodetype *l,headtail *ht) {
        nodetype *n;
        n = (nodetype*)malloc(sizeof(nodetype));
        if (n == NULL) {
            printf("no available memory\n");
            return(1);
        }
        n->previousn = NULL;
        n->nextn = NULL;    
    }
    int Size(headtail *ht) {
        nodetype *N;
        N = ht->head->nextn;
        int count = 0;
        while (N != ht->tail) {
            count++;
            N = N->nextn;
        }
        return count;
    }

    int IsEmpty(headtail *ht) {
        return (ht->head->nextn == NULL);
    }

    int GetFirst(headtail *ht) {
        if (!IsEmpty(ht)) {
            printf("list is empty\n");
            return 1;
        }
        nodetype *N = ht->head->nextn;
        return(N->number);
    }

    int GetLast(headtail *ht) {
        if (IsEmpty(ht)) {
            printf("list is empty\n");
            return 1;
        }
            return (ht->tail->nextn->number);
    }

    nodetype GetNode(headtail *ht,int i) {
        nodetype *find = ht->head->nextn;
        while (find != ht->tail) {
            if (find->number == i)
                return *find;
            find = find-> nextn;
        }
        
    }

    int GetPrev(nodetype *l,headtail *ht) {
        
        if (l == NULL || l->previousn == NULL) {
            printf("List or prevnode is NULL\n");
            return 1;
        }
        return (l->previousn->number);
    }
    
    int GetNext(nodetype *l,headtail *ht) {
        if (l == NULL || l->nextn == NULL) {
            printf("List or Nextnode is Null\n");
            return 1;
        }
        return (l->nextn->number);
    }

    nodetype AddBefore(nodetype *l,headtail *ht,int i) {
        nodetype *NewAdd,*prevpointer,*N = ht->head->nextn;
            if (l == NULL) {
                printf("NULL node\n");
                return(1);
            }
           
                NewAdd =(nodetype*) malloc(sizeof(nodetype));
                if (NewAdd == NULL) {
                    printf("no available memory\n");
                    return(1);
                }
                NewAdd->number = i;
                if (l == ht->head->nextn) {
                    NewAdd->previousn = ht->head;
                    NewAdd->nextn = l;
                    ht->head->nextn = NewAdd;
                    l->previousn = NewAdd;
                }
                else {
                    NewAdd->previousn = l->previousn;
                    prevpointer = l->previousn;
                    prevpointer->nextn = NewAdd;
                    NewAdd->nextn = l;
                    l->previousn = NewAdd;
                }
    }
    nodetype AddAfter(nodetype *l,headtail *ht,int i) {
        nodetype *NewAdd,*prevpointer,*N = ht->head->nextn;
        if (l == NULL) {
            printf("NULL node\n");
            return(1);
        }
            NewAdd =(nodetype*) malloc(sizeof(nodetype));
            if (NewAdd == NULL) {
                printf("no available memory\n");
                return(1);
            }
            NewAdd->number = i;
            if (l == ht->tail->previousn) {
                l->nextn = NewAdd;
                NewAdd->previousn = l;
                NewAdd->nextn = NULL;
                ht->tail->previousn = NewAdd;
            }
            else {
                NewAdd->nextn = l->nextn;
                prevpointer = l->nextn;
                prevpointer->previousn = NewAdd;
                l->nextn = NewAdd;
                NewAdd->previousn = l;
            }
    }
    void AddFirst(headtail *ht,nodetype *l,int){
        nodetype *N,*Link;
        Link = ht->head;
        N =(nodetype*) malloc(sizeof(nodetype));
        N->number = i;
        if (Link == NULL) 
            Link->nextn = N;

        else {
            Link->nextn->previousn = N;
            N->nextn = Link->nextn;
            Link->nextn = N;
            N->previousn = NULL;
        }
    }

    void AddLast(headtail *ht,nodetype *l,int i) {
        nodetype *N,*Link;
        Link = ht->tail;
        N =(nodetype*) malloc(sizeof(nodetype));
        N->number = i;
        if (Link == NULL) 
            Link->previoustn = N;

        else {
            Link->previousn->nextn = N;
            N->previousn = Link->previousn;
            Link->previousn = N;
            N->nextn = NULL;
        }
    }

    void Remove(headtail *ht,int i) {
        nodetype *Link = ht->head->nextn,*Link2 = ht->tail->previousn,*find,*prevpointer,*nextpointer;
        if (ht->head->nextn == ht->tail) {
            printf("List is NULL\n");
            return 1;
        }
        while (Link !=  ht->tail) {
            if (Link->number == i) {
                find = Link;
                Link = Link->nextn;
                free(find);
                continue;
            }
            if (Link2->number == i) {
                find = Link2;
                Link2 = Link2->previousn;
                free(find);
                continue;
            }
             {
                prevpointer = *l->previousn;
                nextpointer = *l->nextn;
                prevpointer->nextn = nextpointer;
                nextpointer->previousn = prevpointer;
                free(*l);
                continue;
            }
            Link = Link->nextn;
        }
    }