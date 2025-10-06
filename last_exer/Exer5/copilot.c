#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EDGES 1000
#define MAX_VERTICES 100

typedef struct {
    int u, v, w;
} Edge;

typedef struct {
    int n; // number of vertices
    int edge_count;
    Edge edges[MAX_EDGES];
    int parent[MAX_VERTICES];
} WeightedUndirectedGraph;

// Union-Find helpers for Kruskal
int find(WeightedUndirectedGraph *g, int x) {
    if (g->parent[x] != x)
        g->parent[x] = find(g, g->parent[x]);
    return g->parent[x];
}

void union_sets(WeightedUndirectedGraph *g, int x, int y) {
    int px = find(g, x);
    int py = find(g, y);
    if (px != py)
        g->parent[py] = px;
}

// Initialize the graph
void Initialize(WeightedUndirectedGraph *g, int n) {
    g->n = n;
    g->edge_count = 0;
    for (int i = 0; i < n; i++)
        g->parent[i] = i;
}

// Insert an edge
void InsertEdge(WeightedUndirectedGraph *g, int u, int v, int w) {
    if (g->edge_count < MAX_EDGES) {
        g->edges[g->edge_count].u = u;
        g->edges[g->edge_count].v = v;
        g->edges[g->edge_count].w = w;
        g->edge_count++;
    }
}

// Show the graph
void ShowGraph(WeightedUndirectedGraph *g) {
    printf("Graph edges:\n");
    for (int i = 0; i < g->edge_count; i++) {
        printf("%d -- %d (weight %d)\n", g->edges[i].u, g->edges[i].v, g->edges[i].w);
    }
}

// Compare function for qsort
int edge_cmp(const void *a, const void *b) {
    Edge *ea = (Edge *)a;
    Edge *eb = (Edge *)b;
    return ea->w - eb->w;
}

// Kruskal's algorithm for MST
void MinimumSpanningTree(WeightedUndirectedGraph *g) {
    int mst_weight = 0;
    int mst_edges = 0;
    Edge mst[MAX_EDGES];

    // Sort edges by weight
    qsort(g->edges, g->edge_count, sizeof(Edge), edge_cmp);

    // Initialize union-find
    for (int i = 0; i < g->n; i++)
        g->parent[i] = i;

    for (int i = 0; i < g->edge_count && mst_edges < g->n - 1; i++) {
        int u = g->edges[i].u;
        int v = g->edges[i].v;
        int w = g->edges[i].w;
        if (find(g, u) != find(g, v)) {
            union_sets(g, u, v);
            mst[mst_edges++] = g->edges[i];
            mst_weight += w;
        }
    }

    printf("Minimum Spanning Tree:\n");
    for (int i = 0; i < mst_edges; i++) {
        printf("%d -- %d (weight %d)\n", mst[i].u, mst[i].v, mst[i].w);
    }
    printf("Total weight: %d\n", mst_weight);
}

// Main function
int main(void) {
    int n, m;
    printf("Δώσε αριθμό κορυφών: ");
    scanf("%d", &n);
    WeightedUndirectedGraph g;
    Initialize(&g, n);

    printf("Δώσε αριθμό ακμών: ");
    scanf("%d", &m);

    printf("Δώσε κάθε ακμή στη μορφή: u v w (π.χ. 0 1 5)\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        InsertEdge(&g, u, v, w);
    }

    ShowGraph(&g);
    MinimumSpanningTree(&g);

    return 0;
}
