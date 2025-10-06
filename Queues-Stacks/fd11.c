#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	
		typedef char airportcode[4];
		typedef struct nodetag {
			airportcode airport;
			struct nodetag *link;
		} nodetype;
		nodetype *nodepointer;
		
	int main (void) {
		airportcode c;
		nodepointer l;
		strcpy(c,"gre");
		printf("%s\n",c);


		l = (nodetype*) malloc(sizeof(nodetype));
		strcpy(l->airport,c);
		printf("%s\n",l->airport);
	}
	int *arr;
 int *arr = (int*) (malloc sizeof(int*));