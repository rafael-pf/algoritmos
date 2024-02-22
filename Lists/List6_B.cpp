#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int,int>> SuperPair;

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

void prism(Graph* g, int s, int d[], int V[]){
    priority_queue<SuperPair, vector<SuperPair>, greater<SuperPair>> heap;
    int p=0,v=0,w=0,peso=0;
    int count=0;
    for(int i=0; i<g->numVertices; i++){
        d[i] = INT_MAX;
        V[i] = -1;
        g->mark[i]=0;
    }
    heap.push({0, {0, 0}});
    d[0]=0;
    for(int i=0; i<g->numVertices; i++){
        do{
            if(heap.empty()) return;
            p = heap.top().second.first;
            v = heap.top().second.second;
            heap.pop();
        }while(g->mark[v]);
        g->mark[v]=1;
        V[v]=p;
        w = first(g, v);
        count=0;
        while(w<g->numVertices){
            if(!g->mark[w]){
                peso = weight(g, v, w);
                if(d[w] > peso){
                    d[w] = peso;
                    heap.push({d[w], {v,w}});
                }
            }
            // w = next(g, v, w);
            if(count+1<g->vertices[v].edges.size()) count++;
            else break;
            w = g->vertices[v].edges[count].value;
        }
    }
}

int main(){

    int n, m, u, v, w;

    cin >> n >> m;
    do{
        if(m == 0){
            cout << "IMPOSSIBLE\n";
            cin >> n >> m;
            continue;
        }
        Graph* g = createGraph(n);
        int d[n], V[n];
        for(int i=0; i<m; i++){
            cin >> u >> v >> w;
            insertEdge(g, u, v, w);
        }
        prism(g, 0, d, V);
        int min=0;
        for(int i=1; i<n; i++){
            if(d[i]>min) min=d[i];
        }
        if(min>0 && min<INT_MAX) cout << min << "\n";
        else cout << "IMPOSSIBLE\n";
        cin >> n >> m;
    }while(!(n==0 && m==0));

    return 0;
}
