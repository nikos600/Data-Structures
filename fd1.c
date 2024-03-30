#include <stdio.h>
#include <stdlib.h>
#include <string.h>

		
		
		 typedef char AirportCode[4];
 			typedef struct nodeTag {
 				AirportCode Airport;
 				struct nodeTag *link;
			} nodetype;
 		typedef nodetype *nodepointer;

	void insertnewlist (char *,nodetype **);
	void printlist(nodetype *);
	void deletelist(nodetype **);



	int main(void) {
		AirportCode C;
 		nodepointer L,K;
		K = (nodepointer) malloc(sizeof(nodetype));
		strcpy(C,"GRE");
		strcpy(K->Airport, C);
 		printf("%s \n", K->Airport);
 		L=(nodepointer)malloc(sizeof(nodetype));
		strcpy(C,"ITA");
 		strcpy(L->Airport, C);
 		printf("%s %s\n", L->Airport,K->Airport);
		
		insertnewlist("BUL",&L);
		insertnewlist("FRA",&L);
		insertnewlist("ESP",&L);
		printlist(L);
		deletelist(&L);
		printlist(L);
		return 0;
	}
		

		void deletelist(nodetype **L) {
			nodepointer previous,current,next;
		if (*L != NULL) {
			if ((*L) ->link == NULL) {
				free(*L);
				previous = *L;
			}
			else {
				previous = *L;
				current = (*L)->link;
				while (strcmp(current->Airport,"FRA") != 0) {
					previous = current;
					current = current->link;
				}
			 next = current->link;
			 free(current);
			 current = next->link;
			 printf("\n  %s       \n",next->Airport);
			}	
		}
		}
		void insertnewlist(char *A,nodetype **L) {
				nodetype *N,*E;
				E = *L;
				N = (nodetype *)malloc(sizeof(nodetype));
				strcpy(N->Airport,A);
				N->link = NULL;
				if (E == NULL) 
					*L = N;
				else {
				while (E->link != NULL) E = E->link;
					E->link = N;
				}
		}

		void printlist(nodetype *L){
			
			while (L != NULL) {
				printf("%s ",  L->Airport);
				L = L->link;
				if (L  != NULL) {printf(",");}
			}
			
			

		}