typedef struct nodetag nodetype;
typedef nodetype *nodepointer;

nodetype createnewnode(nodetype **l);
void insertsecondnode(nodetype *l);
nodetype *searchlist(char *A,nodetype *l);
void deletelastnode(nodetype **l);
nodetype insertnewlastnode(nodetype **l,char *A);
void printlist(nodetype **l);
