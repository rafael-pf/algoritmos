#include <iostream>
#include <vector>
using namespace std;

typedef struct{
    vector<string> elements;
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

int Search(Hash_Table* table, string key){
    int index = H(key, table->m);
    if(!table->elements[index].empty()){
        while(table->elements[index]!=key){
            index++;
            index%=table->m;
        }
        return index;   
    }
    return -1;
}

void RemoveKey(Hash_Table* table, string key){
    int index = Search(table, key);
    if(index!=-1){
        table->size--;
        table->elements[index].clear();
    }
}

void InsertKey(Hash_Table* table, string key){
    if(table->size<table->m){
        int index = H(key, table->m);
        if(table->elements[index].empty()){
            table->elements[index] = key;
        }   
        else{
            while(!table->elements[index].empty()){
                index++;
                index = index % table->m;
            }
            table->elements[index] = key;
        }
        table->size++;
    }
}

int main(){
    
    int M;
    cin >> M;
    Hash_Table* table = create_table(M);
    string comando, texto;

    while(cin >> comando){
        if(comando == "add"){
            cin >> texto;
            InsertKey(table, texto);
        }
        else if(comando == "sch"){
            cin >> texto;
            cout << texto << " " << Search(table, texto) << "\n";
        }
        else if(comando == "rmv"){
            cin >> texto;
            RemoveKey(table, texto);
        }
        else{
            break;
        }
    }
    
    return 0;
}
