#include <iostream>
using namespace std;

typedef struct{
    int maxSize;
    int listSize;
    int curr;
    int* listArray;
}List;

List* createList(int x){
    List* l = new List;
    l->curr=0;
    l->listSize=0;
    l->maxSize=x;
    l->listArray = new int[x];
    return l;
}

void insert(List* l, int x){
    if(l->listSize<l->maxSize){
        int i=l->listSize;
        while(i>l->curr){
            l->listArray[i]=l->listArray[i-1];
            i--;
        }
        l->listArray[l->curr]=x;
        l->listSize++;
    }
}

void remove(List* l){
    if(l->curr>=0 && l->curr < l->listSize){
        int i=l->curr;
        while(i<l->listSize-1){
            l->listArray[i]=l->listArray[i+1];
            i++;
        }
        l->listSize--;
    }
}

void count(const List* l, int x){
    int count=0;
    for(int i=0; i<l->listSize; i++){
        if(l->listArray[i]==x){
            count++;
        }
    }
    cout << count << "\n";
}

void prev(List* l){
    if(l->curr!=0){
        l->curr--;
    }
}

void next(List* l){
    if(l->curr<l->listSize){
        l->curr++;
    }
}

void clear(List* l){
    delete(l->listArray);
    delete(l);
}

int main(){
    int c=0, n=0, x=0;
    string comando;
    cin >> c;
    for(int i=0; i<c; i++){
        cin >> n;
        List* l = createList(n);
        cout << "Caso " << i+1 << ":\n";
        for(int j=0; j<n; j++){
            cin >> comando;
            if(comando=="insert"){
                cin >> x;
                insert(l, x);
            }
            else if(comando=="remove"){
                remove(l);
            }
            else if(comando=="count"){
                cin >> x;
                count(l, x);
            }
            else if(comando=="prev"){
                prev(l);
            }
            else if(comando=="next"){
                next(l);
            }
        }
        clear(l);
    }


    return 0;
}
