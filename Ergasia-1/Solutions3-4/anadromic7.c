#include <stdio.h>
#include <stdlib.h>

 int anadromic(int n,int arr[],int sum,int index,int flag) {
    
    if (sum == 0 && flag) {
        return 1;
    }
    if (index == n) {            
        return 0;
    }

    if (anadromic(n,arr,sum + arr[index],index + 1,1))  /*here i add to the sum the elements of the array*/
        return 1;               /*with the help of index*/
                                /*also i use flag because the function is called exponentially i get many times when sum is 0*/
                                /*so i experiment a little myself and used flag to be 1 when checking the specific element*/
    return anadromic(n,arr,sum,index + 1,1);
 }

    int main(void) {
        int arr[] = {11,10,10,10,10};
        int n = sizeof(arr)/sizeof(arr[0]);     /*with this calculation i get the number of elements of the array*/
        if (anadromic(n,arr,0,0,0)) {
            printf("υπαρχει υποσυνολο με αθροισμα ακριβως 0\n");
        }
        else 
            printf("δεν υπάρχει\n");
            
        return 0;
    }


 