#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    typedef char airportcode[4];
    typedef struct nodetag {
            airportcode airport;
            nodetag *link;
    }nodetype;
   typedef nodetype *nodepointer;


    void insertnewsecondnode(void) {
        nodetype *k;
        n =(nodetype *)malloc(sizeof(nodetype));
        strcpy(k->airport,"GRE");
            k->link = l->link;
            l->link = k;
    }

    nodetype *searchnode(nodetype *l,char *a); {

        nodetype *s;
        s = l;
        if (s != NULL) {
            while (s->link != NULL) {
                if (strcmp(s->airport,a) == 0)
                    return s;
                else 
                    s = s->link;
                }

            return 0;

        }
    }

    void deletenode(nodetype **l,char *a) {
        nodetype *j,*prevnode,*curnode;

        if (*l != NULL) {
            if (*l->link == NULL)  
                free(*l);
                *l = NULL;
        }
        else {
            prevnode = *l; 
            curnode = *l->link;
            while (curnode->link != NULL) {
                prevnode = curnode;
                curnode = curnode->link;
            }
            prevnode->link = NULL;
            free[curnode];
         
        }
     
    }

    void insertlastnode(nodetype **l,char a) {
        nodetype *n;
        n = (nodetype *)malloc(sizeof(nodetype));
        strcpy(n->airport,a);
        n->link = NULL;
            if (*l == NULL)
                *l = n; 
            else {
                while (*l->link != NULL) *l = *l->link;
                *l->link = n;
            }
    }

    void printlist (nodetype *l) {
        nodetype *n;
        n = l;

            while (n != NULL) {
                printf(",%s ",n->airport);
                n= n->link;
                if (n != NULL) printf(",");
            }
           
    }
