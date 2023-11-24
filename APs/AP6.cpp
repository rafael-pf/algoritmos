#include <iostream>
#include <list>
using namespace std;

typedef struct{
    int m;
    int count;
    list<int> H;
}Dictionary;

int h(int k){
    return k%10;
}

Dictionary* create_dict(int size){
    Dictionary* d = new Dictionary;
    d->m = size;
    d->count = 0;
    for(int i=0; i<size; i++){
        d->H = new list;
            
    }
    return d; 
}

int main(){



    return 0;
}