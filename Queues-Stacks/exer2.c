#include <stdio.h>
#include <stdlib.h>
#include "exer2.h"


typedef struct stackqueue stacknode;
  struct stackqueue {
     struct stack *next;
     int data;
     static int count;
    };
    stacknode s1,s2;
    typedef struct {
      stacknode *itemlist;
      int count;
    }stack;

  int empty(stacknode *s1) {
      return (s1->data == 0);
  }
  int full(stacknode *) {
    return 0;
  }
  void initialize(s1,stack *l) {
      l->count = 0;
      s1->data = 0;
      s1->next = NULL;
    }
  stacknode *stack_push(stack *l,int data) {
        stacknode *show = malloc(sizeof(stacknode));
        if(!empty(s1)) {
           s1 = show;
           s1->next = NULL;
            return 0;
          }
        l->count += 1;
        show->next = l->itemlist->s1;
        l->itemlist = show;
        }
        
  }

  stacknode *sort_stack(stacknode *s1,stacknode *s2,stack *l) {
          int max = 0;
          stacknode *s2 = malloc(sizeof(stacknode));
        for (;l->count > 0;l->count -= 1)
          for (;s1->next != NULL;s1 = s1 ->next) {
              if (s1->data > max) 
                  max = s1->data;


          } 
          s2 = hold;
          stacknode *s2 = malloc(sizeof(stacknode));
          s2 = s2 ->next;


  }


int main(void) {
  stacknode *s1,*s2;
  sort_stack(s1,s2);
}
