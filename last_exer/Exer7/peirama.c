#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "skip.h"



/*InsertEdge(&G,0,2);
    InsertEdge(&G,0,3);
    InsertEdge(&G,0,1);
    InsertEdge(&G,1,2);
    InsertEdge(&G,1,4);
    InsertEdge(&G,1,6);
    InsertEdge(&G,7,8); */




static link head, z;
static int N, lgN;




Key key (Item item) {
    return item;
}

link NEW(Item item, int k) {
  if (k == 0) k = 1;
   int i; 
   link x = malloc(sizeof (*x));
    x->next = malloc(k*sizeof(link));
    x->item = item; x->sz = k;
    for (i = 0; i < k; i++) x->next[i] = z;
    return x;
  }
Skiplist STinit(int max) {
    link st = malloc(sizeof(*st));
    st->N = 0;
    st->lgN = 1;
    st->z = NEW(NULLitem, max);
    for (int i = 0; i < max; i++) st->z->next[i] = st->z;

    st->head = NEW(NULLitem, max);
    for (int i = 0; i < max; i++) st->head->next[i] = st->z;

    return st;
}

int randX(int *lgN)
  { int i, j, t = rand();
    for (i = 1, j = 2; i < *lgN; i++, j += j)
      if (t > RAND_MAX/j) break;
    if (i > *lgN) *lgN = i;
    return i;
  }

void insertR(Skiplist st,link t, link x, int k)
  { Key v = key(x->item);
    if (t == st->z) return;
    if (t == x || t->next[k] == st->z) return;
    if (less(v, key(t->next[k]->item)))
      {
        if (k < x->sz)
          { x->next[k] = t->next[k];
            t->next[k] = x; }
        if (k == 0) return;
        insertR(st,st->header, x, k-1); return;
      }
    insertR(st,t->next[k], x, k);
  }
void STinsert(Skiplist st,key v)
  { 
    int r = randX(&st->lgN);
    link x = NEW(v,r);
    insert(st,st->header,x,st->lgN);
    st->N++;
   }


void STdelete(Skiplist st,Key v) {
  link c = st->header;
for (int i = st->lgN - 1; i >= 0; i--) {
    while (c->next[i] != st->z && less(key(t->next[i]-item,v))) {
        link rem = c->next[i];
        if (i == 0) {
            free(rem->next);
            free(rem);
        }
    }
}
  st->N--;
}



  void print(Skiplist st) {
    
    link r = st->header->next[0];
    if (r == st->z) {
        printf("null list\n");
        return;
    }
    while (r != st->z) {
        printf("%d",r->item);
        r = r->next[0];
    }
    printf("\n");
  }




    Skiplist merge(Skiplist list1, Skiplist list2) {
    if (list1 == NULL || list2 == NULL)
        return NULL;

    Skiplist list3 = malloc(sizeof(*list3));
    list3->lgN = (list1->lgN > list2->lgN) ? list1->lgN : list2->lgN;
    list3->max = (list1->max > list2->max) ? list1->max : list2->max;
    list3->N = 0;

    list3->z = NEW(NULLitem, list3->max);
    for (int i = 0; i < list3->max; i++)
        list3->z->next[i] = list3->z;

    list3->head = NEW(NULLitem, list3->max);
    for (int i = 0; i < list3->max; i++)
        list3->head->next[i] = list3->z;

    link update[list3->max];
    for (int i = 0; i < list3->max; i++)
        update[i] = list3->head;

    bool unflipped = true;

        link x = list1->header->next[0];
        link x1 = list2->header->next[0];


        while (x != z && x1 != z) {
          Key keyl1 = key(list1->header->next[0]->item);
          Key keyl2 = key(list2->header->next[0]->item);


          if (keyl1 > keyl2) {
                Skiplist temp = list1;
                list1 = list2;
                list2 = temp;
                Key tempkey = keyl1;
                keyl1 = keyl2;
                keyl2 = tempkey;
                unflipped = false;
            }
           
        
            int lvl = 0;
         do {
                update[lvl]->next[lvl] = list1->header->next[lvl];
                lvl++;
            }while (lvl < list3->max && list1->header->next[lvl] != list1->z && key(list1->header->next[lvl]->item) <= keyl2); 

            lvl--;  
            link k = list1->header->next[lvl];
            for (int i = lvl;i >= 1;i--) {
                while (k->next[i] != list1->z && key(k->next[i]->item) <= keyl2) 
                    k = k->next[i];
                
                update[i] = k;
                list1->header->next[i] = k->next[i];
            }

            if (eq(keyl2,key(x->item))) {
                if (unflipped) {
                    x->item = list2->header->next[0]->item;
                }
                link temp1 = list2->header->next[0];
                for (int i = 0; i < temp1->sz;i++) 
                    list2->header->next[i] = temp1->next[i];
                //free(temp1->next);
                free(temp1);
            }
          }
         Skiplist leftover;
        if (list2->header->next[0] == list2->z) 
            leftover = list1;
        else 
            leftover = list2;


        for (int i = 1;i < leftover->max;i++) 
            update[i]->next[i] = leftover->header->next[i];

        for (int i = leftover->max; i < list3->max;i++) 
            update[i]->next[i] = list3->z;

        while (list3->max > 1 && list3->header->next[list3->max - 1] == list3->z)
            list3->max = list3->max - 1;
            
          free(list1);
          free(list2);

        return list3;
}
  




#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "skip.h"



Key key (Item item) {
    return item;
}

link NEW(Item item, int k)
  { int i; link x = malloc(sizeof *x);
    x->next = malloc(k*sizeof(link));
    x->item = item; x->sz = k;
    for (i = 0; i < k; i++) x->next[i] = z;
    return x;
  }
void STinit(int max)
  {
    N = 0; lgN = 0;
    z = NEW(NULLitem, 0);
    head = NEW(NULLitem, lgN);
  }

int randX()
  { int i, j, t = rand();
    for (i = 1, j = 2; i < lgN; i++, j += j)
      if (t > RAND_MAX/j) break;
    if (i > lgN) lgN = i;
    return i;
  }
void insertR(link t, link x, int k)
  { Key v = key(x->item);
    if (less(v, key(t->next[k]->item)))
      {
        if (k < x->sz)
          { x->next[k] = t->next[k];
            t->next[k] = x; }
        if (k == 0) return;
        insertR(t, x, k-1); return;
      }
    insertR(t->next[k], x, k);
  }
void STinsert(Key v)
  { insertR(head, NEW(v, randX()), lgN); N++; }

void deleteR(link t, Key v, int k)
  { link x = t->next[k];
    if (!less(key(x->item), v))
      {
        if (eq(v, key(x->item)))
          { t->next[k] = x->next[k]; }
        if (k == 0) { free(x); return; }
        deleteR(t, v, k-1); return;
      }
    deleteR(t->next[k], v, k);
  }
void STdelete(Key v)
  { deleteR(head, v, lgN); N--; }


  void print(link list) {
    link r = list->next[0];
    if (r == NULL) {
        printf("null list\n");
        return;
    }
    printf("print just the base level 0 to see the reults\n");

    while (r != z) {
        printf("%d %d",r->item,r->item);
        r = r->next[0];
    }
  }




    link merge(link list1,link list2) {
        int r;
        link union1,union2;
        bool unflipped = true;

        
        int level3 = (list1->sz > list2->sz) ? list1->sz : list2->sz;
        link list3 = NEW(NULLitem,level3);
        link update[level3];

        for (int i = 0;i < level3;i++)
            update[i] = list3;

        link x = list1->next[0];
        link x1 = list2->next[0];


        while (x != z && x1 != z) {
          Key keyl1 = key(list1->next[0]->item);
          Key keyl2 = key(list2->next[0]->item);


          if (keyl1 > keyl2) {
                link temp = list1;
                list1 = list2;
                list2 = temp;
                Key tempkey = keyl1;
                keyl1 = keyl2;
                keyl2 = tempkey;
                unflipped = false;
            }
           
        
            int lvl = 0;
         do {
                update[lvl]->next[lvl] = list1->next[lvl];
                lvl++;
            }while (lvl < level3 && list1->next[lvl] && list1->next[lvl]->item <= keyl2); 

            lvl--;  
            link k = list1->next[lvl];
            for (int i = lvl;i >= 1;i--) {
                while (k->next[i] != z && key(k->next[i]->item) <= keyl2) 
                    k = k->next[i];
                
                update[i] = k;
                list1->next[i] = k->next[i];
            }

            if (eq(keyl2,key(x->item))) {
                if (unflipped) {
                    x->item = list2->next[0]->item;
                }
                link temp1 = list2->next[0];
                for (int i = 0; i < temp1->sz;i++) 
                    list2->next[i] = temp1->next[i];
                free(temp1);
            }
          }
         link leftover;
        if (list2->next[0] == z) 
            leftover = list1;
        else 
            leftover = list2;


        for (int i = 1;i < leftover->sz;i++) 
            update[i]->next[i] = leftover->next[i];

        for (int i = leftover->sz + 1; i < level3;i++) 
            update[i]->next[i] = z;

        while (level3 > 1 && list3->next[level3 - 1] == z)
            list3->sz = list3->sz - 1;
            
        free(list1);
        free(list2);

        return list3;
}
  
