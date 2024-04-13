#include <stdio.h>

typedef struct node{
    int data;
    int counter;
    struct node *next;
}
struct node initiliaze(node *nodepoint,int data) {
    node *newnode = malloc(sizeof(node));
    newnode->data = 0;
    newnode->counter = 0;
    newnode->next = NULL;
    return newnode;
}
    void empty(struct node *nodepoint) {
        return !nodepoint->next;
    }
    void push(node **nodepoint,int data){
        node *newnode = initialize(data);
        newnode->next = *nodepoint;
        *nodepoint = newnode;
        printf("%d pushed it into the stack\n",data);
    }
    void pop(node **nodepoint) {
        if (!empty(*nodepoint))
            printf("empty stack\n");
        node *temp;
        *temp = *nodepoint;
        *nodepoint = (*nodepoint)->next;
        free(temp);
    }
    struct  connect_stack(node **nodepoint,int counter)
        node *afterpop;
        if (*nodepoint->next == NULL)
            return NULL;
        while(nodepoint->counter != counter)
            nodepoint = nodepoint->next;
        afterpop = *nodepoint;
        while (afterpop->counter!= (counter + 1))
            afterpop = afterpop->next;
        *nodepoint->next = afterpop;
            
 /*int main(void) {
   int h = 1,n = 5,f = n;
   printf("0,");
   
   for (int i = 1;i <= n;i++) {
        printf("%d,",i);
   }
  for (int c = 1;c < n;c++) {
        for (int i = 1;i <= f;i++) {
            printf("%d",i);
        }
        printf(",");
        f -= 1;
        }
} 

for (int i = 1;i <= n;i++) {
        printf("%d,",i);
   }
   for (int i = 1;i <= n;i++) {
        printf("%d ",i);
   }  */
