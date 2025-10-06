#include <stdlib.h>
#include <limits.h>
#include "Max.h"
#include "acutest/acutest.h"




max *l1 = NULL;
max *insert(max *l,int i);
int findmax(max *l);


void test_findmax() {
    

    l1 = insert(l1,10);
    l1 = insert(l1,17);
    l1 = insert(l1,25);
    TEST_CHECK(findmax(l1) == 25);
}
 typedef struct Maxtag {
        struct Maxtag *link;
        int number;
    } max;

TEST_LIST = {
   
    { "test_findmax",test_findmax   },
    { NULL, NULL },
};
