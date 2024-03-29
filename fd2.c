#include <stdio.h>

typedef struct fold {
			char er[100];
			struct fold *next;
		} folder;


		int main(void) {
		folder sdi19 = {"/", NULL};
		folder nikos = {"nikos",&sdi19};
		folder personal= {"personal",&nikos};
		for (folder *iterator = &personal;iterator;iterator = iterator ->next) {
            printf("%s\n",iterator->er);
        }
        }