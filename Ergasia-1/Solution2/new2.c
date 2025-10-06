#include <stdio.h>
#include <stdlib.h>

typedef struct Nodetag {
    int number;
    struct Nodetag *previousn;
    struct Nodetag *nextn;
} nodetype;

nodetype *Create() {
    nodetype *n = (nodetype*)malloc(sizeof(nodetype));
    if (n == NULL) {
        printf("no available memory\n");
        return NULL;
    }                           
    n->previousn = NULL;       
    n->nextn = NULL;    
    return n;
}

int Size(nodetype *l) {
    nodetype *N = l;
    int count = 0;
    while (N != NULL) {
        count++;
        N = N->nextn;
    }
    return count;
}

int IsEmpty(nodetype *l) {
    return (l == NULL);
}

int GetFirst(nodetype *l) {
    if (l == NULL) {
        printf("List is empty\n");
        return -1;
    }
    return l->number;
}

int GetLast(nodetype *l) {
    if (l == NULL) {
        printf("List is empty\n");
        return -1;
    }
    nodetype *n = l;
    while (n->nextn != NULL) { 
        n = n->nextn;
    }
    return n->number;
}

nodetype *GetNode(nodetype *l, int i) {
    nodetype *find = l;
    while (find != NULL) {       /*finding the i element */
        if (find->number == i)  /*in a loop while */
            return find;        /*and if you find it*/
        find = find->nextn;     /* return it*/
    }
    return NULL;
}

int GetPrev(nodetype *l) {
    if (l == NULL || l->previousn == NULL) {
        printf("No previous node\n");
        return -1;
    }
    return l->previousn->number;
}

int GetNext(nodetype *l) {
    if (l == NULL || l->nextn == NULL) {
        printf("No next node\n");
        return -1;
    }
    return l->nextn->number;
}

void AddBefore(nodetype *target, int i) {
    if (target == NULL) {
        printf("Target node is NULL\n");
        return;
    }
    nodetype *NewAdd = (nodetype*)malloc(sizeof(nodetype));
    if (NewAdd == NULL) {
        printf("NewAdd is NULL\n");
        return;     
    }
    NewAdd->number = i;
    NewAdd->nextn = target;     /*add the element before that i have it as argument*/
    NewAdd->previousn = target->previousn; /*with these steps*/
    if (target->previousn != NULL) {
        target->previousn->nextn = NewAdd;
    }
    target->previousn = NewAdd;
}

void AddAfter(nodetype *target, int i) {
    if (target == NULL) {
        printf("Target node is NULL\n");
        return;
    }
    nodetype *NewAdd = (nodetype*)malloc(sizeof(nodetype));
    if (NewAdd == NULL) {
        printf("NewAdd is NULL\n");
        return;
    }
    NewAdd->number = i;
    NewAdd->nextn = target->nextn;
    NewAdd->previousn = target;
    if (target->nextn != NULL) {
        target->nextn->previousn = NewAdd;
    }
    target->nextn = NewAdd;
}

void AddFirst(nodetype **l, int i) {
    nodetype *N = (nodetype*)malloc(sizeof(nodetype));
    if (N == NULL) {
        printf("No available memory\n");
        return;
    }
    N->number = i;
    N->nextn = *l;
    N->previousn = NULL;
    if (*l != NULL) {
        (*l)->previousn = N;
    }
    *l = N;
}

void AddLast(nodetype **l, int i) {
    nodetype *N = (nodetype*)malloc(sizeof(nodetype));
    if (N == NULL) {
        printf("No available memory\n");
        return;
    }
    N->number = i;
    N->nextn = NULL;
    if (*l == NULL) {
        N->previousn = NULL;
        *l = N;
    } else {
        nodetype *Link = *l;
        while (Link->nextn != NULL) {
            Link = Link->nextn;
        }
        Link->nextn = N;
        N->previousn = Link;
    }
}

void Remove(nodetype **l, int i) {
    if (*l == NULL) {
        printf("List is empty\n");
        return;
    }
    nodetype *Link = *l;
    while (Link != NULL) {
        if (Link->number == i) {               
            if (Link->previousn != NULL) {   /*check here if the element is the first where the pointer *l points*/
                Link->previousn->nextn = Link->nextn; 
            } else {
                *l = Link->nextn;          /*if yes then i change *l to the next */
            }
            if (Link->nextn != NULL) {      /*the same with the last element*/
                Link->nextn->previousn = Link->previousn;
            }
            free(Link);
            return;
        }
        Link = Link->nextn;
    }
    printf("Node with number %d not found\n", i);
}

void Print(nodetype *l) {
    nodetype *N = l;
    while (N != NULL) {
        printf("%d", N->number);
        N = N->nextn;
        if (N != NULL) printf(", ");
    }
    printf("\n");
}

int main(void) {
    nodetype *l = NULL;
    l = Create();
    AddFirst(&l, 10);
    AddFirst(&l, 7);
    AddLast(&l, 100);

    printf("size of list: %d\n", Size(l));
    printf("get first i: %d\n", GetFirst(l));
    printf("get last i: %d\n", GetLast(l));
    nodetype *target = GetNode(l, 10);
    AddBefore(target, 8);
    AddAfter(target, 8);
    if (IsEmpty(l) == 1)
        printf("empty\n");
    else 
        printf("not empty\n");
    printf("print List\n");
    Print(l);

    printf("delete node\n");
    Remove(&l, 100);
    Print(l);

    return 0;
}