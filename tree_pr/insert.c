#include <stdio.h>
#include <stdlib.h>



    typedef int item;

    typedef struct nikos {
        item age;
        struct nikos *next;
    }nikosin;



        void insert(nikosin *r,item x) {
                if (r == Null) exit(1);
                nikosin f = malloc(sizeof(nikosin));
                f->age = x;
                f->next = NULL;
                

                else 

                    while (r->next != NULL) r = r->next;
                    r->next = f;
                    r->age = x;
                   
        }

        nikosin new(nikosin *r) {
            nikosin *f = malloc(sizeof(nikosin));
            if (r == NULL) r-> next = f;
            while (r->next != NULL) r = r->next; 
            r->next = f;
        }

        nikosin search(nikosin *r,item x) {
            if (r == NULL) return NULL;

            while (r->next != r) {
                if (r->age == x) {
                    return x;
                }
                else 
                    r = r-> next;
            }
             
        }























int main(void) {}