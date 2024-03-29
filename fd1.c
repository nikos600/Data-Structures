#include <stdio.h>
#include <stdlib.h>
#include <string.h>


		
		 typedef char AirportCode[4];
 			typedef struct NodeTag {
 				AirportCode Airport;
 				struct NodeTag *Link;
			} NodeType;
 		typedef NodeType *NodePointer;



	int main(void) {
		AirportCode C;
 		NodePointer L,K;
		K = (NodePointer) malloc(sizeof(NodeType));
		strcpy(C,"GRE");
		strcpy(K->Airport, C);
 		printf("%s \n", K->Airport);
 		L=(NodePointer)malloc(sizeof(NodeType));
		strcpy(C,"ITA");
 		strcpy(L->Airport, C);
 		printf("%s %s\n", L->Airport,K->Airport);
				return 0;
	}
		