#include <iostream>
#include <list>
using namespace std;

typedef struct{
    int index;
    int wt;
}Edge;

typedef struct v{
    list <Edge> edges;
    int value;
}Vertices;

typedef struct{
    Vertices* vertices;
    int numEdges;
    int numVertices;
}Graph;

Graph* createGraph(int n){
    Graph* g = new Graph;
    g->numEdges=0;
    g->numVertices=0;
    return g;
}

int main(){

   

    return 0;
}
