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

int weight(Graph* g, int v, int w){
    for(int i=0; i<g->vertices[v].edges.size(); i++){
        if(g->vertices[v].edges[i].value==w){
            return g->vertices[v].edges[i].weight;
        }
    }
    return 0;
}

void insertEdge(Graph* g, int v, int w, int weight){
    g->vertices[v].edges.push_back({weight, w});
    g->vertices[w].edges.push_back({weight, v});
    g->numEdges++;
}

int getMark(Graph* g, int v){
    return g->mark[v];
}

void setMark(Graph* g, int v, int val){
    g->mark[v]=val;
}

void dijkstra(Graph* g, int s, int t, int d[]){
    int* P = new int[g->numVertices];
    priority_queue<SuperPair, vector<SuperPair>, greater<SuperPair>> heap;
    int p=0,v=0,w=0;
    for(int i=0; i<g->numVertices; i++){
        d[i] = INT_MAX;
        // P[i] = -1;
        setMark(g, i, 0);
    }
    heap.push({0, {s, s}});
    d[s]=0;
    for(int i=0; i<g->numVertices; i++){
        do{
            if(heap.empty()) return;
            p = heap.top().second.first;
            v = heap.top().second.second;
            heap.pop();
        }while(getMark(g, v));
        setMark(g, v, 1);
        // P[v] = p;
        w = first(g, v);
        while(w<g->numVertices){
            if(!getMark(g, w) && d[w] > d[v] + weight(g, v, w)){
                d[w] = d[v] + weight(g, v, w);
                heap.push({d[w], {v, w}});
            }
            w = next(g, v, w);
        }
    }
}

int main(){

    int N, n, m, s, t, u, v, w;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> n >> m >> s >> t;
        Graph* g = createGraph(n);
        int d[n];
        for(int j=0; j<m; j++){
            cin >> u >> v >> w;
            insertEdge(g, u, v, w);
        }
        dijkstra(g, s, t, d);
        if(d[t]!=INT_MAX) cout << "Case #" << i+1 << ": " << d[t] << "\n";
        else cout << "Case #" << i+1 << ": " << "unreachable" << "\n";
    }

    return 0;
}
