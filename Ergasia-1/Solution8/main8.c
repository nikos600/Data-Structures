#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p1queue.h"

int main(int argc,char *argv[]) {
    if (argc < 2) {
       printf("more or less args\n");
       return 0;
    }
    queueht first = Queueinit();
    for (int i = 0;i < strlen(argv[1]); i++) {
         int numb = (int)(argv[1][i] - '0');  //here i take the input argument and cast it to int 
         QUEUEput(first, numb);     //and add it to a queue 
     }                              //the input argument of numbers should be without blanks 
     Print(first);
     Sort_Queue(first);
     Print(first);
     Queueget(first);
     while (!QUEUEempty(first)) {
         Queueget(first);
     }
     free(first);
     
     return 0;
 }