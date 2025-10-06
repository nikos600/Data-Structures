#include <stdio.h>
#include <stdlib.h>
#include "list1.h"




int main(void) {
  nodetype *l = NULL;
  insertnewlastnode(&l, "CYP");
  insertnewlastnode(&l, "GRE");
  insertnewlastnode(&l, "BUL");
  printlist(&l);  
  insertsecondnode(l);
  searchlist("CYP", l);
  deletelastnode(&l);
  return 0;
}

