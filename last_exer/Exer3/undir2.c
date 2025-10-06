#include <stdio.h>
#include <stdlib.h>
#include "undirgraph.h"


 

void Initialize(Graph *s,Vertex nov) {
    s->n = nov;
    for (int i = 0;i < nov;i++) {
        s->edges[i] = NULL;
    }
}

 void InsertEdge(Graph *s,Vertex endpoint1,Vertex newedge) {
        ped edge1 = malloc(sizeof(Edge));
        edge1->endpoint = endpoint1;
    edge1->next = s->edges[newedge];
    s->edges[newedge] = edge1;
    
    ped edge2 = malloc(sizeof(Edge));
    edge2->endpoint = newedge;
    edge2->next = s->edges[endpoint1];
    s->edges[endpoint1] = edge2;
 }

    void ShowGraph(Graph *s) {
        for (int i = 0;i < s->n;i++) {
            Edge *temp = s->edges[i];
            printf("vertex %d: ",i);
            while (temp != NULL) {
                printf("%d   ",temp->endpoint);
                 temp = temp->next;
            }
            printf("\n");
        }
    }


    void BreadthFirst(Graph *G,Vertex start) {

            Queue Q;
            Boolean visited[MAXVERTEX];
            Vertex v, w;
            Edge *curedge;

            for (v=0; v < G->n; v++)
                visited[v]= FALSE;

            InitializeQueue(&Q);
            Insert(start,&Q);
            visited[start]=TRUE;


                    while (!Empty(&Q)) {
                        Remove(&Q, &start);;
                        
    
                        curedge = G->edges[start];  /* curedge is a pointer to the first edge (v,_) of V */
                        while (curedge){
                            w = curedge->endpoint;  /* w is a successor of v and (v,w) is the current edge */
                            if (!visited[w]) {
                                Insert(w, &Q);
                                visited[w]=TRUE;
                                printf("edge tree %d\n",w);
                            }
                            else 
                                printf("cross tree %d\n",w);
                            curedge=curedge->next;  /*curedge is a pointer to the next edge (v,_) of V */
                        }
                    }
        }


        void IsConnected(Graph *G) {
    Queue Q;
    Boolean visited[MAXVERTEX];
    Vertex v, w;
    Edge *curedge;
    int count = 0;
    int activeVertices = 0;

    for (v = 0; v < G->n; v++) {
        visited[v] = FALSE;
        if (G->edges[v] != NULL)  // Κόμβος με έστω μία ακμή
            activeVertices++;
    }
    printf("%d active \n",activeVertices);
    InitializeQueue(&Q);

    // Ξεκίνα BFS από τον πρώτο κόμβο που έχει έστω μία ακμή
    for (v = 0; v < G->n; v++) {
        if (G->edges[v] != NULL) {
            Insert(v, &Q);
            break;
        }
    }

    while (!Empty(&Q)) {
        Remove(&Q, &v);

        if (!visited[v]) {
            visited[v] = TRUE;
            count++;
        }

        curedge = G->edges[v];
        while (curedge) {
            w = curedge->endpoint;
            if (!visited[w])
                Insert(w, &Q);

            curedge = curedge->next;
        }
    }

    if (count == activeVertices)
        printf("connected\n");
    else
        printf("not connected\n");
}


        
        int *ShortestPaths(Graph *G, Vertex start) {
    Queue Q;
    Boolean visited[MAXVERTEX];
    Vertex v, w;
    Edge *curedge;
    int *shortest = malloc(sizeof(int) * G->n); // δυναμικός πίνακας για αποστάσεις

    for (v = 0; v < G->n; v++) {
        visited[v] = FALSE;
        shortest[v] = -1; // -1 σημαίνει ότι δεν υπάρχει μονοπάτι
    }

    InitializeQueue(&Q);
    Insert(start, &Q);
    visited[start] = TRUE;
    shortest[start] = 0;

    while (!Empty(&Q)) {
        Remove(&Q, &v);
        curedge = G->edges[v];

        while (curedge) {
            w = curedge->endpoint;
            if (!visited[w]) {
                visited[w] = TRUE;
                shortest[w] = shortest[v] + 1;
                Insert(w, &Q);
            }
            curedge = curedge->next;
        }
    }

    return shortest;
}

            void ConnectedComponents(Graph *G) {
                
            Queue Q;
            Boolean visited[MAXVERTEX];
            Vertex v, w;
            Edge *curedge;
            int count = 0;
            for (v=0; v < G->n; v++)
                visited[v]=FALSE;

            InitializeQueue(&Q);
                for (v=0; v < G->n; v++) {
                    if (!visited[v]){
                        Insert(v, &Q);
                        while (!Empty(&Q)) {
                            Remove(&Q, &w);
                            if (!visited[w]) {
                                visited[w]=TRUE;
                            curedge=G->edges[w];  /* curedge is a pointer to the first edge (v,_) of V */
                            while (curedge) {
                                w=curedge->endpoint;  /* w is a successor of v and (v,w) is the current edge */
                                if (!visited[w])
                                    Insert(w, &Q);
                                    
                                    count += 1;
                                }
                                curedge=curedge->next;  /*curedge is a pointer to the next edge (v,_) of V */
                            }   
                        }
                    }
                }
        }

        
        int Empty(Queue *pq) {
            return (pq->front == NULL);
        }
            


        void Visit(Vertex w) {
            printf("%d\n",w);
        }


        void InitializeQueue(Queue *pq) {
            pq->front = NULL;
            pq->rear = NULL;
        }


        void Insert(Vertex x,Queue *pq) {
            Queuenode *new;
            new = malloc(sizeof(Queue));
            new->data = x;
            new->link = NULL;
            if (pq->rear == NULL) {
                pq->rear = new;
                pq->front = new;
            }
            else 
                pq->rear->link = new;
                pq->rear = new;
        }

        void Remove(Queue *pq,Vertex *v) {
            if (pq->front == NULL) {
                printf("null queue\n");
                exit(1);
            }
            Queuenode *pq1 = pq->front;
            *v = pq1->data;
            pq->front = pq1->link;
            if (pq->front == NULL)
                pq->rear = NULL;
            
            free(pq1);
            
           
        }

        