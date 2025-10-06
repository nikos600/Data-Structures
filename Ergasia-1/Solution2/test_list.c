#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Experimental3.h"
#include "acutest/acutest.h"

nodetype *l1 = NULL;
nodetype *l2 = NULL;

typedef struct Nodetag {
    int number;
    struct Nodetag *previousn;
    struct Nodetag *nextn;
} nodetype;

void test_Create() {
    
    l2 = Create();
    TEST_CHECK(l2->nextn == NULL);
}

void test_Size() {
    
    AddFirst(&l1,2);
    TEST_CHECK(Size(l1) == 1 );
}
void test_IsEmpty() {
    TEST_CHECK(IsEmpty(l1) == 0 || IsEmpty(l1) == 1);
}

 void test_GetFirst() {
    AddFirst(&l2,10);
    
    TEST_CHECK(GetFirst(l2) == 10);
    free(l2);
}

void test_GetLast() {
    AddFirst(&l2,10);
    AddFirst(&l2,20);
    AddFirst(&l2,30);
    TEST_CHECK(GetLast(l2) == 10);
    free(l2);
}
void test_GetNode() {
    AddFirst(&l1,15);
    AddFirst(&l1,2);
    AddFirst(&l1,7);
    nodetype *check = GetNode(l1,15);
    TEST_CHECK( check->number == 15);
    free(l1);
}
void test_GetPrev() {
    AddFirst(&l1,2);
    AddFirst(&l1,7);
    AddFirst(&l1,27);
    nodetype *target = GetNode(l1,2);
    AddFirst(&l1,16);
    
    TEST_CHECK(GetPrev(target) == 7);
    free(l1);
}
void test_GetNext() {
    AddFirst(&l1,36);
    AddFirst(&l1,77);
    AddFirst(&l1,48);
    nodetype *target = GetNode(l1,48);
    AddFirst(&l1,31);
    TEST_CHECK(GetNext(target) == 77);
    free(l1);
}
void test_AddBefore() {
    AddFirst(&l1,2);
    AddFirst(&l1,7);
    AddFirst(&l1,27);
    nodetype *target = GetNode(l1,7);
    AddBefore(target,68);
    TEST_CHECK(target->previousn->number == 68);
    free(l1);
}
void test_AddAfter(){
    AddFirst(&l1,2);
    AddFirst(&l1,7);
    AddFirst(&l1,27);
    nodetype *target = GetNode(l1,7);
    AddAfter(target,68);
    TEST_CHECK(target->nextn->number == 68);
    free(l1);
}
void test_AddFirst() {
    l1 = NULL;
    AddFirst(&l1,2);
    AddFirst(&l1,7);
    TEST_CHECK(l1 != NULL);
    TEST_CHECK(l1->number == 7);
    TEST_CHECK(l1->nextn->number == 2);
    free(l1->nextn);
    free(l1);
}
void test_AddLast(){
    l1 = NULL;
    AddFirst(&l1,2);
    AddFirst(&l1,7);
    AddLast(&l1,100);
    TEST_CHECK(GetLast(l1) == 100);
    free(l1);
}
void test_Remove() {
    AddFirst(&l1,2);
    AddFirst(&l1,7);
    AddLast(&l1,150);
    AddLast(&l1,100);
    Remove(&l1,100);
    TEST_CHECK(GetLast(l1) == 150);
}

TEST_LIST = {
   
    { "test_Create",test_Create   },
    { "test_Size", test_Size   }, 
    { "test_IsEmpty",  test_IsEmpty  }, /
    { "GetFirst",  test_GetFirst  }, 
    { "test_GetLast",  test_GetLast  },
    { "test_GetNode",  test_GetNode  },
    { "test_GetPrev",  test_GetPrev  },
    { "test_GetNext",  test_GetNext  },
    { "test_AddBefore",  test_AddBefore  },
    { "test_AddAfter",  test_AddAfter  },
    { "test_AddFirst",  test_AddFirst  },
    { "test_AddLast",  test_AddLast  },
    { "test_Remove",  test_Remove  },
    { NULL, NULL } /* zeroed record marking the end of the list */
};
