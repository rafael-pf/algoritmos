#include <iostream>
#include <vector>
using namespace std;

typedef struct{
    string name;
    string cpf;
    bool wasFull;
}Element;

typedef struct{
    vector<Element> elements;
    int m;
    int cnt;
}Dictionary;

Dictionary* createDictionaty(int size){
    Dictionary* d = new Dictionary;
    d->cnt=0;
    d->m=size;
    d->elements.resize(size);
    return d;
}

int H(Dictionary* d, string key){
    int sum=0;
    for(int  i=0; i<key.length(); i++){
        sum+=(key[i]-'0');
    }
    return sum%d->m;
}

int search(Dictionary* d, string key){
    int index = H(d, key);
    int aux = index;
    int i=1;
    if(d->elements[index].wasFull){
        if(d->elements[index].cpf==key){
            return index;
        }
        else{
            while(d->elements[aux].wasFull && i<=d->m && d->elements[aux].cpf!=key){
                aux += i;
                aux %= d->m;
                i++;
            }
            if(d->elements[aux].cpf==key){
                return aux;
            }
        }
    }
    return -1;
}   

void insert(Dictionary* d, string name, string key){
    if(d->cnt<d->m && search(d, key)==-1){
        int index = H(d, key);
        int aux = index;
        int i = 1;
        if(d->elements[index].cpf.empty()){
            d->elements[index].cpf = key;
            d->elements[index].name = name;
            d->elements[index].wasFull = true;
            d->cnt++;
        }
        else{
            while(!d->elements[aux].cpf.empty() && i<=d->m){
                aux += i;
                aux %= d->m;
                i++;
            }
            if(d->elements[aux].cpf.empty()){
                d->elements[aux].cpf = key;
                d->elements[aux].name = name;
                d->elements[aux].wasFull = true;
                d->cnt++;
            }
        }
    }
}

void remove(Dictionary* d, string key){
    int index = search(d, key);
    if(index!=-1){
        d->elements[index].cpf.clear();
        d->elements[index].name.clear();
        d->cnt--;
    }
}

void print_d(Dictionary* d){
    for(int i=0; i<d->m; i++){
        cout << i << ". ";
        if(!d->elements[i].cpf.empty()) cout << d->elements[i].name << " - " << d->elements[i].cpf << " - " << d->elements[i].wasFull << "\n";
        else cout << "--- " << d->elements[i].wasFull << "\n";
    }
}

int main(){

    int n=0, k=0;
    string comando, nome, cpf;
    cin >> n;

    Dictionary* d = createDictionaty(n);

    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> comando;
        if(comando=="add"){
            cin >> nome >> cpf;
            insert(d, nome, cpf);
            print_d(d);
            cout << "\n";
        }
        else if(comando=="find"){
            cin >> cpf;
            k = search(d, cpf);
            if(k==-1) cout << k << "\n";
            else cout << d->elements[k].name << " " << k << "\n";
        }
        else if(comando=="rmv"){
            cin >> cpf;
            remove(d, cpf);
            cout << "\n";
            print_d(d);
            cout << "\n";
        }
    }

    delete (d);

    return 0;
}
