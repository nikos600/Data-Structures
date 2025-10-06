#include <stdio.h>
#include <stdlib.h>


   long long int continuous(long long int x) {
        if (x == 1) 
            return 1;           
        else 
            return  x * continuous(x-1);
        
    }
        
    
    int main (void) {

        printf("%lld\n", continuous(21));
        
    }