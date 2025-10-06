typedef struct Stacknodetag Stacknode;
typedef struct Stack Stack;

int IsEmpty(Stack *);
int priorityops(char);
char Operator1();
void InitializeStack(Stack *);
void Push(char );
void Push1(float ,Stack *);
char Pop();
void Pop1(Stack *,float *);
char *InfixtoPostfix(char *);
void InterpretPostfix(char *);