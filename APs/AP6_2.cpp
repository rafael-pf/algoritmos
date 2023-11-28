#include <iostream>
#include <vector>
using namespace std;

typedef struct{
    vector<vector<string>> elements;
    int m;
    int size;
}Hash_Table;

Hash_Table* create_table(int M){
    Hash_Table* table = new Hash_Table;
    table->m = M;
    table->size=0;
    table->elements.resize(M);
}

int H(string key, int M){
    int s=key.size();
    int sum=0;
    for(int i=0; i<s; i++){
        sum+=key[i];
    }
    return abs(sum)%M;
}

void insert(Hash_Table* table, string key){
    
}

int main(){
    
    
    return 0;
}