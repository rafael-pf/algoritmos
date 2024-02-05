#include <iostream>
#include <vector>
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

void graphTraverseDFS(Graph* g){
    for(int v=0; v<g->numVertices; v++){
        setMark(g, v, 0);        
    }
    for(int v=0; v<g->numVertices; v++){
        if(!getMark(g, v)){
            //traverse(g, i);
        }
    }
}

void graphTraverseBFS(Graph* g){
    for(int v=0; v<g->numVertices; v++){
        setMark(g, v, 0);        
    }
    for(int v=0; v<g->numVertices; v++){
        if(!getMark(g, v)){
            //traverse(g, i);
        }
    }
}

void DFS(Graph* g, int v){
    //previsit
    setMark(g, v, 1);
    int w = first(g, v);
    while(w<g->numVertices){
        if(!getMark(g, w)) DFS(g, w);
        w = next(g, v, w);
    }
    //posvisit
}



int main(){




    return 0;
}
