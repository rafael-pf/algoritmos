#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> SuperPair;

typedef struct {
    int weight;
    int value;
} Edge;

typedef struct {
    vector <Edge> edges;
    int value;
} Vertices;

typedef struct{
    Vertices* vertices;
    bool* mark;
    int numEdges;
    int numVertices;
} Graph;

Graph* createGraph(int n){
    Graph* g = new Graph;
    g->numEdges=0;
    g->numVertices=n;
    g->mark = new bool[n];
    g->vertices = new Vertices[n];
    return g;
}

int first(Graph* g, int v){
    if(g->vertices[v].edges.empty()) return g->numVertices;
    return g->vertices[v].edges.front().value;
}

int next(Graph* g, int v, int w){
    if(g->vertices[v].edges.empty()) return g->numVertices;
    bool achei=false;
    for(int i=0; i<g->vertices[v].edges.size(); i++){
        if(achei) return g->vertices[v].edges[i].value;
        if(g->vertices[v].edges[i].value==w){
            achei=true;
        }
    }
    return g->numVertices;
}

void insertEdge(Graph* g, int v, int w, int weight){
    Edge e;
    e.value=w;
    e.weight=weight;
    g->vertices[v].edges.push_back(e);
    g->numEdges++;
}

int getMark(Graph* g, int v){
    return g->mark[v];
}

void setMark(Graph* g, int v, int val){
    g->mark[v]=val;
}

void dijkstra(Graph* g, int s, int* d){
    int* P = new int(g->numVertices);
    priority_queue<SuperPair, vector<SuperPair>, greater<SuperPair>> heap;
    int p,v;
    for(int i=0; i<g->numVertices; i++){
        d[i] = INFINITY;
        P[i] = -1;
    }
    heap.push({0, {s, s}});
    for(int i=0; i<g->numVertices; i++){
        do{
            if(heap.empty()) return;
            p = heap.top().second.first;
            v = heap.top().second.second;
            heap.pop();
        }while(getMark(g, v));
    }
}
