#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "anadromic.h"
#include "acutest/acutest.h"
int anadromic(int n,int arr[],int sum,int k,int found);

void test_anadromic() {
    int arr[] = {10,0,0,-10,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    TEST_CHECK(anadromic(n,arr,0,0,0) == 1);
}

TEST_LIST = {
   
    { "test_anadromic",test_anadromic   },
    { NULL, NULL },
};