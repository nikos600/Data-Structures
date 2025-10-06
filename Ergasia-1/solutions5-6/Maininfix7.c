#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "infix7.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("more arguments \n");
        return 1;
    }
    char *resultpost = InfixtoPostfix(argv[1]);
    InterpretPostfix(resultpost);
    return 0;
}