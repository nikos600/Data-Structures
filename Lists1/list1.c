#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list1.h"

typedef char airportcode[4];
  typedef struct nodetag{
        airportcode airport;
        struct nodetag *link;
   }nodetype;
 typedef nodetype *nodepointer;

nodetype createnewnode(nodetype **l) {
    nodepointer b,r,c;
    (*l) = b;
    b = (nodepointer)malloc(sizeof(nodetype));
    strcpy(b->airport,"BUL");  
    r = (nodepointer)malloc(sizeof(nodetype));
    strcpy(r->airport,"ROM");
    c = (nodepointer)malloc(sizeof(nodetype));
    strcpy(c->airport,"CYP");
    b->link = r;
    r->link = c;
    c->link = NULL;
    
}
   void insertsecondnode(nodetype *l) {
    nodepointer p;
    p=(nodepointer)malloc(sizeof(nodetype));
    strcpy(p->airport,"GRE");
    p->link = l->link;
    l->link = p;
   }
  

   nodetype *searchlist(char *A,nodetype *l) {
      nodetype *n;
      n = l;
      while (n != NULL) {
        if (strcmp(n->airport,A) == 0) 
          return n;
        else 
          n = l->link;
      }
      return n;
   }
    void deletelastnode(nodetype **l) {
      nodetype *prev,*current;
      if (*l != NULL) {
          if ((*l)->link == NULL) 
            free(*l);
          *l =  NULL;
      }
      else 
        prev = *l;
        current = (*l)->link;
        while (current->link != NULL) {
            prev->link = current;
            current = current->link;    
        }
        prev->link = NULL;
        free(current);
    }

      nodetype insertnewlastnode(nodetype **l,char *A) {
          nodetype *g,*k;
          k = (nodepointer)malloc(sizeof(nodetype));
          strcpy(k->airport,A);
          k->link = NULL;
       
          if ((*l) == NULL) 
            *l = k;
          else {
            g = *l;
            while (g->link != NULL)  g = g->link; 
            g->link = k;
          }
      }

      void printlist(nodetype **l) {
          nodetype *j;
          *l = j;
          if (j->link == NULL) 
            printf("emptylist\n");
          else {
            while (j != NULL) {
              printf("%s  ",j->airport);
              j = j->link;
            }
            printf("%s\n",j->airport);
          } 

      }



      