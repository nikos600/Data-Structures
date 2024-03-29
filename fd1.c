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
 		NodePointer L;
	    strcpy(C, "BRU");
 		printf("%s\n", C);
 		L=(NodePointer)malloc(sizeof(NodeType));
 		strcpy(L->Airport, C);
 		printf("%s \n", L->Airport);
		return 0;
	}
