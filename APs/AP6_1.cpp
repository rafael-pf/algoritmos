#include <iostream>
#include <vector>
#define M 10
using namespace std;

typedef struct{
    vector<vector<int>> elements;
    int m;
    int size;
}Hash_Table;

int H(int key){
    return key % 10;
}

Hash_Table* create_table(){
    Hash_Table* table = new Hash_Table;
    table->m = M;
    table->size=0;
    table->elements.resize(M);
    return table;
}

void InsertKey(Hash_Table* table, int key){
    int index = H(key);
    if(table->elements[index].size()==0){
        table->size++;
    }
    table->elements[index].push_back(key);
}

void printTable(Hash_Table* table){
    for(int i=0; i<table->m; i++){
        cout << i << " - ";
        for(int j=0; j<table->elements[i].size(); j++){
            cout << table->elements[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){

    int n=0, k=0;
    Hash_Table* table = create_table();

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> k;
        InsertKey(table, k);
    }

    printTable(table);
    delete(table);
    
    return 0;
}