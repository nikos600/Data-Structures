typedef struct STnode* link;
typedef int Item;
typedef int Key;
extern  Item NULLitem;

#define less(a,b) ((a) < (b))
#define eq(a,b) ((a) == (b))




    
    struct STnode { 
        link head;
        link z;
        Item N;
        lnt lgN; 
    };




Key key(Item item);
link NEW(Item item, int k);
void STinit(int max);
int randX();
void insertR(link, link, int);
void STinsert(Key);
void deleteR(link,Key, int);
void STdelete(Key);
link merge(link,link);
void print(link ); 
