#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

typedef struct{
    int index;
    int wt;
}Edge;

typedef struct v{
    vector <int> edges;
    int value;
    int cost;
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
    for(int i=0; i<n; i++){
        g->vertices[i].cost=0;
    }
    return g;
}

int first(Graph* g, int v){
    if(g->vertices[v].edges.empty()) return g->numVertices;
    return g->vertices[v].edges.front();
}

int next(Graph* g, int v, int w){
    if(g->vertices[v].edges.empty()) return g->numVertices;
    bool achei=false;
    for(int i=0; i<g->vertices[v].edges.size(); i++){
        if(achei) return g->vertices[v].edges[i];
        if(g->vertices[v].edges[i]==w){
            achei=true;
        }
    }
    return g->numVertices;
}

void setEdge(Graph* g, int u, int v, int wt){
    g->vertices[u].edges.push_back(v);
    g->vertices[v].cost++;
    g->numEdges++;
}

void delEdge(Graph* g, int u, int v){
    for(int i=0; i<g->vertices[u].edges.size(); i++){
        if(g->vertices[u].edges[i]==v){
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
    int w = first(g, v);
    while(w<g->numVertices){
        if(!getMark(g, w)){
            DFS(g, w);
        }
        w = next(g, v, w);
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
    priority_queue<int, vector<int>, greater<int> > temp;
    
    for(int i=0; i<g->numVertices; i++){
        if(!g->vertices[i].cost){
            temp.push(i);
        }
    }

    while(temp.size()>0){
        int v = temp.top();
        temp.pop();
        q.push(v);

        for(int i=0; i<g->vertices[v].edges.size(); i++){
            //reduz o "custo" para desbloquear
            g->vertices[g->vertices[v].edges[i]].cost--;

            if(!g->vertices[g->vertices[v].edges[i]].cost){
                temp.push(g->vertices[v].edges[i]);
            }
        }
    }

    if(q.size()==g->numVertices){
        for(int i=0; i<g->numVertices; i++){
            cout << q.front()+1 << " ";
            q.pop();
        }
    }
    else{
        cout << "Sandro fails.";
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
    int w = first(g, v);
    while(w<g->numVertices){
        if(!getMark(g, w)){
            toposort(g, w, s);
        }
        w = next(g, v, w);
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
        cout << s.top()+1 << " ";
        s.pop();
    }
}

int main(){

    
    int n, m, u, v;
    cin >> n >> m;

    Graph* graph = createGraph(n);

    for(int i=0; i<m; i++){
        cin >> u >> v;
        setEdge(graph, u-1 ,v-1, 1);
    }


    BFS(graph, 0);
    cout << "\n";

    return 0;

    return 0;
}
