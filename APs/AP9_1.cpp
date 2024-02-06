#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct{
    int** matriz;
    int numEdge;
    int numVertices;
    int* Mark;
}Graph;

Graph* create_graph(int n){
    Graph* g = new Graph;
    g->numEdge = 0;
    g->numVertices = n;
    g->matriz = new int*[n];
    for(int i=0; i<n; i++){
        g->matriz[i] = new int[n];
    }
    g->Mark = new int[n];
    return g;
}

int first(Graph* g, int v){
    for(int i=0; i<g->numVertices; i++){
        if(g->matriz[v][i]) return i;
    }
    return g->numVertices;
}

int next(Graph* g, int v, int w){
    for(int i=w+1; i<g->numVertices; i++){
        if(g->matriz[v][i]) return i;
    }
    return g->numVertices;
}

void setEdge(Graph* g, int i, int j, int wt){
    if(!wt) return;
    if(!g->matriz[i][j]) g->numEdge++;
    g->matriz[i][j]=wt;
}

void delEdge(Graph* g, int i, int j){
    if(g->matriz[i][j]) g->numEdge--;
    g->matriz[i][j]=0;
}

void setMark(Graph* g, int v, int visited){
    g->Mark[v] = visited;    
}

int getMark(Graph* g, int v){
    return g->Mark[v];
}

void DFS(Graph* g, int v){
    //previsit
    cout << v << " ";
    setMark(g, v, 1);
    int w = first(g, v);
    while(w<g->numVertices){
        if(!getMark(g, w)) DFS(g, w);
        w = next(g, v, w);
    }
    //posvisit
}

void BFS(Graph* g, int start){
    queue<int> q;
    q.push(start);
    setMark(g, start, 1);
    while(q.size()>0){
        int v = q.front();
        q.pop();
        //previsit
        cout << v << " ";
        int w = first(g, v);
        while(w<g->numVertices){
            if(!getMark(g, w)){
                setMark(g, w, 1);
                q.push(w);
            }
            w = next(g, v, w);
        }
        //posvisit
    }
}

void graphTraverseDFS(Graph* g, int start){
    for(int v=0; v<g->numVertices; v++){
        setMark(g, v, 0);        
    }
    for(int v=start; v<g->numVertices; v++){
        if(!getMark(g, v)){
            DFS(g, v);
        }
    }
}

void graphTraverseBFS(Graph* g, int start){
    for(int v=0; v<g->numVertices; v++){
        setMark(g, v, 0);        
    }
    for(int v=start; v<g->numVertices; v++){
        if(!getMark(g, v)){
            BFS(g, v);
        }
    }
}

int main(){

    int n, k, u, v;
    string comand;
    cin >> n >> k;

    Graph* graph = create_graph(5);

    for(int i=0; i<k; i++){
        cin >> comand;
        if(comand=="add"){
            cin >> u >> v;
            setEdge(graph, u ,v, 1);
        }
        else if(comand=="BFS"){
            cin >> u;
            graphTraverseBFS(graph, u);
            cout << "\n";
        }
        else if(comand=="DFS"){
            cin >> u;
            graphTraverseDFS(graph, u);
            cout << "\n";
        }
    }

    return 0;
}
