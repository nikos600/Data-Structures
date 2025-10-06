#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef char airportcode[4];
  typedef struct nodetag{
        airportcode airport;
        struct nodetag *link;
   }nodetype;
 typedef nodetype *nodepointer;

void createnewnode(nodetype **l) {
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
    strcpy(p->airport,"ITA");
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
        nodetype *PreviousNode, *CurrentNode;
        if (*l != NULL) {
            if ((*l)->link == NULL){
                free(*l);
                *l=NULL;
            } 
            else {
                PreviousNode=*l;
                CurrentNode=(*l)->link;
                while (CurrentNode->link != NULL){
                    PreviousNode=CurrentNode;
                    CurrentNode=CurrentNode->link;
                }
                PreviousNode->link=NULL;
                free(CurrentNode);
            }
        }
}
      void insertnewlastnode(nodetype **l,char *A) {
          nodetype *g,*k;
          k = (nodetype *)malloc(sizeof(nodetype));
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

      void printlist(nodetype *l) {
          nodetype *j;
          j = l;
        
            while (j != NULL) {
              printf("%s  ",j->airport);
              j = j->link;
            }
            printf("\n");
    }
         

      
      int main(void) {
        nodetype *l = NULL;
        insertnewlastnode(&l, "CYP");
        insertnewlastnode(&l, "GRE");
        insertnewlastnode(&l, "BUL");
        printlist(l);  
        insertsecondnode(l);
        printlist(l); 
        searchlist("CYP", l);
        deletelastnode(&l);
        printlist(l);
        deletelastnode(&l);
        printlist(l);
        return 0;
      }
      