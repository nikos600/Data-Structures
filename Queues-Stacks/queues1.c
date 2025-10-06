#include <stdio.h>
#include <stdlib.h>

struct students {
    int age;
    struct students *link;
}students;
typedef struct {
 students *show;
}point;
 int empty(point *s) {
  return (s->show->age == 0);
}
int full(point *s) {
    return 0; 
}
void initialize(point *s) {
    s->show->age = 0;
    s->link = NULL;
}

void push(point *s,int age) {
    students *new = malloc(sizeof(students));
    if (s->show == NULL)
        printf("empty stack\n");
    else {
        new->age = age;
        new->link = s->show;
        s->show = new;

    }
}   

void pop (point *s) {
    students temp;
    if (s->show == NULL)
        printf("pop in an empty stack\n");
    else {
        temp = s->show;
        s->show = temp->link;
        free(temp);
    }


}

  
    
typedef struct students students;
int main(void) {
    students s1 = NULL;
    return 0;  
}