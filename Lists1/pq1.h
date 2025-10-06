#include “pqtypes.h” 

void initialitize(priorityqueue *);
int empty (priorityqueue *);
int full(priorityqueue *);
void insert (priorityqueue *,pqitem);
pqitem remove (priorityqueue *);