#define max 10

    typedef int Vertex;
    

typedef struct edge {
    Vertex endpoint;
    struct edge *next;
}Edge;
typedef Edge *ped;

    typedef struct graph {
        int n;
        ped *edges[max];
    }Graph;

 typedef struct queue {
    int data;
    struct Queue *link;
 } Queuenode;

    typedef struct {
        Queuenode *front;
        Queuenode *rear;
    } Queue;