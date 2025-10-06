#include <stdio.h>
#include <stdlib.h>
#include "anadromic.h"

int anadromic(int n,int arr[],int sum,int k,int found) {
    printf("check %d %d \n",sum,k);
    if (sum == 0 && found) {
        
        return 1;
        
    }
    if (k == n) {
        return 0;
    }
    if (anadromic(n,arr,sum + arr[k],k + 1,1))
        return 1;

    return anadromic(n,arr,sum,k + 1,found);
}
  

int main (void) {
    int arr[] = {10,10,10,10,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    if (anadromic(n,arr,0,0,0))
        printf("υπαρχει υποσυνολο με αθροισμα ακριβως 0\n");
    else 
        printf("δεν υπάρχει\n");

    return 0;
}