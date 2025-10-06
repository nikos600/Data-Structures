typedef struct stack stacknode;

stacknode *stack_push(stacknode *,int);
stacknode *stack_remove(stacknode *);
int empty(stacknode *);
int full(stacknode *);
void initialize(stacknode *,stack *);