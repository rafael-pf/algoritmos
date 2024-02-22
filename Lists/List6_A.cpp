#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> SuperPair;

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
    priority_queue<SuperPair, vector<SuperPair>, greater<SuperPair>> heap;
    int v=0,w=0, peso=0;
    for(int i=0; i<g->numVertices; i++){
        d[i] = INT_MAX;
        g->mark[i]=0;
    }
    heap.push({0, s});
    d[s]=0;
    for(int i=0; i<g->numVertices; i++){
        do{
            if(heap.empty()) return;
            v = heap.top().second;
            if(v == t) return;
            heap.pop();
        }while(g->mark[v]);
        g->mark[v]=1;
        w = first(g, v);
        while(w<g->numVertices){
            if(!g->mark[w]){
                peso = weight(g, v, w);
                if(d[w] > d[v] + peso){
                    d[w] = d[v] + peso;
                    heap.push({d[w], w});
                }
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
        if(!m){
            cout << "Case #" << i+1 << ": " << "unreachable" << "\n";
            continue;
        }
        Graph* g = createGraph(n);
        int d[n];
        for(int j=0; j<m; j++){
            cin >> u >> v >> w;
            insertEdge(g, u, v, w);
        }
        if(m==1){
            cout << "Case #" << i+1 << ": " << w << "\n";
            continue;
        }
        dijkstra(g, s, t, d);
        if(d[t]!=INT_MAX) cout << "Case #" << i+1 << ": " << d[t] << "\n";
        else cout << "Case #" << i+1 << ": " << "unreachable" << "\n";
    }

    return 0;
}
