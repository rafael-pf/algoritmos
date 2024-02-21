#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

typedef struct {
    string value;
    int rank;
}Teste;

typedef struct {
    string value;
    string rank;
}Gambiarra;

typedef struct {
    vector <int> edges;
    int value;
    int rank;
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
        g->vertices[i].rank=0;
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
    for(int i=0; i<g->vertices[u].edges.size(); i++){
        if(g->vertices[u].edges[i]==v){
            return;
        }
    }
    g->vertices[u].edges.push_back(v);
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

void BFS(Graph* g, int start, int ahmadIndex){
    queue<int> q;
    q.push(ahmadIndex);
    setMark(g, ahmadIndex, 1);
    while(q.size()>0){
        int v = q.front();
        q.pop();
        int w = first(g, v);
        while(w < g->numVertices){
            if(!getMark(g, w)){
                setMark(g, w, 1);
                q.push(w);
                g->vertices[w].rank = g->vertices[v].rank+1;
            }
            w = next(g, v, w);
        }
    }
}

void graphTranverseBFS(Graph* g, int ahmadIndex){
    for(int v=0; v<g->numVertices; v++){
        setMark(g, v, 0);
    }
    BFS(g, ahmadIndex, ahmadIndex);
    for(int v=0; v<g->numVertices; v++){
        if(!getMark(g, v)){
            BFS(g, v, ahmadIndex);
        }
    }
}


int main(){

    // ler e processar

    int n, k, count=0;
    int ahmadIndex=0;
    string name1, name2, name3;
    cin >> n;

    for(int i=0; i<n; i++){
        count=0;
        cin >> k;
        map<string, int> db;
        Graph* g = createGraph(k*9);
        vector<Teste> testes;
        vector<Gambiarra> gambiarras;
        ahmadIndex=0;
        for(int j=0; j<k; j++){
            cin >> name1 >> name2 >> name3;
            if(db.find(name1)==db.end()){
                db.insert({name1, count});
                count++;
                if(name1=="Ahmad"){
                    ahmadIndex=count-1;
                }
            }
            if(db.find(name2)==db.end()){
                db.insert({name2, count});
                count++;
                if(name2=="Ahmad"){
                    ahmadIndex=count-1;
                }
            }
            if(db.find(name3)==db.end()){
                db.insert({name3, count});
                count++;
                if(name3=="Ahmad"){
                    ahmadIndex=count-1;
                }
            }
            setEdge(g, db[name1], db[name2], 1);
            setEdge(g, db[name2], db[name1], 1);
            setEdge(g, db[name1], db[name3], 1);
            setEdge(g, db[name3], db[name1], 1);
            setEdge(g, db[name2], db[name3], 1);
            setEdge(g, db[name3], db[name2], 1);
        }
        cout << db.size() << "\n";
        // graphTranverseBFS(g, ahmadIndex);
        for(int j=0; j<g->numVertices; j++){
            setMark(g, j, 0);
        }
        BFS(g, ahmadIndex, ahmadIndex);
        // for(const auto& entry : db){
        //     cout << entry.first << " " << entry.second << "\n";
        // }
        for(const auto& entry : db){
            if(g->vertices[entry.second].rank==0 && entry.first!="Ahmad"){
                gambiarras.push_back({entry.first, "undefined"});
            }
            else{
               testes.push_back({entry.first, g->vertices[entry.second].rank});
            }
        }
        sort(testes.begin(), testes.end(), [](const Teste &a, const Teste &b){
            return a.rank < b.rank;
        });
        for(int j=0; j<testes.size(); j++){
            cout << testes[j].value << " " << testes[j].rank << "\n";
        }
        for(int j=0; j<gambiarras.size(); j++){
            cout << gambiarras[j].value << " " << gambiarras[j].rank << "\n";
        }
        delete(g);
        db.clear();
    }
    return 0;
}
