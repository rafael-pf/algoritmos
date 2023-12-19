#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef struct{
    string value;
    string key;
    bool wasFull=false;
    bool isFull=false;
}Element;

typedef struct{
    vector<Element> elements;
    int m;
    int cnt;
}Dictionary;

Dictionary* createDictionaty(int size){
    Dictionary* d = new Dictionary;
    d->elements.resize(size);
    d->m = size;
    d->cnt=0;
    return d;
}

int H(Dictionary* d, string key){
    int h=0;
    for(int i=0; i<key.length(); i++){
        h+=(key[i]*(i+1));
    }
    h*=19;
    return h % 101;
}

int search(Dictionary* d, string key){
    int index = H(d, key);
    int aux = index;
    if(d->elements[index].wasFull){
        if(d->elements[index].key==key){
            return index;
        }
        else{
            //probing
            for(int j=1; j<20 && d->elements[aux].wasFull && d->elements[aux].key!=key; j++){
                aux = (index + j*j + 23* j) % 101;
            }
            if(d->elements[aux].key==key){
                return aux;
            }
        }
    }
    return -1;
}

void insert(Dictionary* d, string value, string key){
    if(d->cnt<d->m && search(d, key)==-1){
        int index = H(d, key);
        int aux = index;
        if(!d->elements[index].isFull){
            d->elements[index].key = key;
            d->elements[index].value = value;
            d->elements[index].wasFull = true;
            d->elements[index].isFull = true;
            d->cnt++;
        }
        else{
            //probing
            for(int j=1; j<20 && d->elements[aux].isFull; j++){
                aux = (index + j*j + 23* j) % 101;
            }
            if(!d->elements[aux].isFull){
                d->elements[aux].key = key;
                d->elements[aux].value = value;
                d->elements[aux].wasFull = true;
                d->elements[aux].isFull = true;
                d->cnt++;
            }
        }
    }
}

void remove(Dictionary* d, string key){
    int index = search(d, key);
    if(index!=-1){
        d->elements[index].key.clear();
        d->elements[index].value.clear();
        d->elements[index].isFull=false;
        d->cnt--;
    }
}

void print(Dictionary* d){
    cout << d->cnt << "\n";
    for(int i=0; i<101; i++){
        if(d->elements[i].isFull){
            cout << i << ":" << d->elements[i].key << "\n"; 
        }
    }
}

int main(){

    int n=0, k=0, m=0;
    string comando;
    string key;

    cin >> m;
    while(m>0){
        Dictionary* d = createDictionaty(101);
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> comando;
            if(comando.substr(0, 3)=="ADD"){
                key = comando.substr(4);
                insert(d, key, key);
            }
            else if(comando.substr(0, 3)=="DEL"){
                key = comando.substr(4);
                remove(d, key);
            }
        }

        print(d);
        delete(d);
        m--;
    }

    return 0;
}