#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

typedef struct{
    int index;
    int wt;
}Edge;

typedef struct v{
    vector <Edge> edges;
    int value;
}Vertices;

typedef struct{
    Vertices* vertices;
    bool* mark;
    int numEdges;
    int numVertices;
}Graph;

Graph* createGraph(int n){
    Graph* g = new Graph;
    g->numEdges=0;
    g->numVertices=n;
    g->mark = new bool[n];
    g->vertices = new Vertices[n];
    return g;
}

void setEdge(Graph* g, int u, int v, int wt){
    g->vertices[u].edges.push_back({.index= v, .wt=wt});
    g->numEdges++;
}

void delEdge(Graph* g, int u, int v){
    for(int i=0; i<g->vertices[u].edges.size(); i++){
        if(g->vertices[u].edges[i].index==v){
            g->vertices[u].edges.erase(g->vertices[u].edges.begin()+i);
            g->numEdges--;
        }
    }
}

bool getMark(Graph* g, int v){
    return g->mark[v];
}

void setMark(Graph* g, int v, bool val){
    g->mark[v]=val;
}

void DFS(Graph* g, int v){
    // previsit
    setMark(g, v, 0);
    int index=0;
    int w = g->vertices[v].edges[index].index;
    while(w<g->numVertices){
        if(!getMark(g, w)){
            DFS(g, w);
        }
        index++;    
        w = g->vertices[v].edges[index].index;
    }
    // posvisit
}

void graphTranverseDFS(Graph* g){
    for(int v=0; v<g->numVertices; v++){
        setMark(g, v, 0);
    }
    for(int v=0; v<g->numVertices; v++){
        if(!getMark(g, v)){
            DFS(g, v);
        }
    }
}

void BFS(Graph* g, int start){
    queue<int> q;
    int index=0;
    q.push(start);
    setMark(g, start, 1);
    while(q.size()>0){
        int v = q.front();
        q.pop();
        int w = g->vertices[v].edges[index].index;
        while(w < g->numVertices){
            if(!getMark(g, w)){
                setMark(g, w, 1);
                q.pop();
            }
            index++;
            w = g->vertices[v].edges[index].index;
        }
    }
}

void graphTranverseBFS(Graph* g){
    for(int v=0; v<g->numVertices; v++){
        setMark(g, v, 0);
    }
    for(int v=0; v<g->numVertices; v++){
        if(!getMark(g, v)){
            BFS(g, v);
        }
    }
}

void toposort(Graph* g, int v, stack<int> &s){
    // previsit
    setMark(g, v, 1);
    int index=0;
    int w = g->vertices[v].edges[index].index;
    while(w<g->numVertices){
        if(!getMark(g, w)){
            toposort(g, w, s);
        }
        index++;    
        w = g->vertices[v].edges[index].index;
    }
    // posvisit
    s.push(v);
}

void graphTranverseTop(Graph* g){

    stack <int> s;

    for(int v=0; v<g->numVertices; v++){
        setMark(g, v, 0);
    }
    for(int v=0; v<g->numVertices; v++){
        if(!getMark(g, v)){
            toposort(g, v, s);
        }
    }
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}

int main(){

    int n, m, u, v;
    cin >> n >> m;

    Graph* graph = createGraph(n);

    for(int i=0; i<m; i++){
        cin >> u >> v;
        setEdge(graph, u ,v, 1);
    }

    for(int i=0; i<n; i++){
        graphTranverseTop(graph);
        cout << "\n";
    }

    return 0;
}
