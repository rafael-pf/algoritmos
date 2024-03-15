#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> Pair; 

typedef struct{
    int value;
    int weight;
}Edge;

typedef struct{
    vector<Edge> edges;
    int value;
}Vertice;

typedef struct{
    int numEdges;
    int numVertices;
    Vertice* vertices;
    int* mark;
}Graph;

Graph* createGraph(int n){
    Graph* g = new Graph;
    g->mark = new int[n];
    g->numEdges=0;
    g->numVertices=n;
    g->vertices=new Vertice[n];
    return g;
}

void setEdge(Graph* g, int u, int v, int w){
    g->vertices[u].edges.push_back({v, w});
    g->vertices[v].edges.push_back({u, w});
    g->numEdges++;
}

void setMark(Graph* g, int u, int value){
    g->mark[u] = value;
}

int getMark(Graph* g, int u){
    return g->mark[u];
}

int first(Graph* g, int u){
    if(g->vertices[u].edges.empty()) return g->numVertices;
    return g->vertices[u].edges.front().value;
}

int weight(Graph* g, int u, int v){
    for(int i=0; i<g->vertices[u].edges.size(); i++){
        if(g->vertices[u].edges[i].value==v){
            return g->vertices[u].edges[i].weight;
        }
    }
    return 0;
}

void dijkstra(Graph* g, int s, int d[]){
    int v, w, count, peso;
    for(int i=0; i<g->numVertices; i++){
        d[i] = INT_MAX;
        g->mark[i]=0;
    }
    priority_queue<Pair, vector<Pair>, greater<Pair>> heap;
    heap.push({0, s});
    d[s]=0;
    for(int i=0; i<g->numVertices; i++){
        do{
            if(heap.empty()) return;  
            v = heap.top().second;
            heap.pop();
        }while(getMark(g, v));
        setMark(g, v, 1);
        w = first(g, v);
        count = 0;
        while(w<g->numVertices){
            if(!getMark(g, w)){
                peso = weight(g, v, w);
                if(d[w]>d[v]+peso){
                    d[w]=d[v]+peso;
                    heap.push({d[w], w});
                }
            }
            if(count+1<g->vertices[v].edges.size()) count++;
            else break;
            w = g->vertices[v].edges[count].value;
        }
    }
}

int main(){
    int N, K;
    cin >> N >> K;
    int S[N], d[N];
    Graph* g = createGraph(N);
    // int **M
    for(int i=0; i<N; i++){
        cin >> S[i];
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<K && i+j+1<N; j++){
            setEdge(g, i, i+j+1, (int) abs(S[i]-S[i+j+1]));
        }
    }

    dijkstra(g, 0, d);

    cout << d[N-1];

    return 0;
}