#include <stdio.h>
#include <stdlib.h>
#include "Experimental3.h"

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