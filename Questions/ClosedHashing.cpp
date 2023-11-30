#include <iostream>
#include <vector>
using namespace std;

typedef struct{
    string name;
    string cpf;
    bool wasFull=false;    
}Element;

typedef struct{
    vector<Element> elements;
    vector<int> p_array;
    int m;
    int cnt;
}Dictionary;

Dictionary* createDictionaty(int size, vector<int> p_array){
    Dictionary* d = new Dictionary;
    d->m=size;
    d->cnt=0;
    d->elements.resize(size);
    d->p_array = p_array;
    return d;
}

int H(Dictionary* d, string k){
    int sum=0;
    for(int i=0; i<k.length(); i++){
        sum+=k[i]-'0';
    }
    return abs(sum) % d->m;
}

int search(Dictionary* d, string k){
    int index = H(d, k);
    int aux = index;
    int i=1;
    if(d->elements[index].wasFull){
        if(d->elements[index].cpf==k){
            return index;
        }
        else{
            while(d->elements[aux].wasFull && d->elements[aux].cpf!=k && i<=d->p_array.size()){
                aux = index + d->p_array[i-1];
                aux %= d->m;
                i++;
            }
            if(d->elements[aux].cpf==k){
                return aux;
            }
        }
    }
    return -1;
}

void insert(Dictionary* d, string k, string n){
    if(d->cnt<d->m && search(d, k)==-1){
        int index = H(d, k);
        int aux = index;
        int i = 1;
        if(d->elements[index].cpf.empty()){
            d->elements[index].cpf = k;
            d->elements[index].name = n;
            d->elements[index].wasFull = true;
            d->cnt++;
        }
        else{
            while(!d->elements[aux].cpf.empty() && i<=d->p_array.size()){
                aux = index + d->p_array[i-1];
                aux %= d->m;
                i++;
            }
            if(d->elements[aux].cpf.empty()){
                d->elements[aux].cpf = k;
                d->elements[aux].name = n;
                d->elements[aux].wasFull = true;
                d->cnt++;
            }
        }
    }
}

void print_d(Dictionary* d){
    for(int i=0; i<d->m; i++){
        cout << i << ". ";
        if(!d->elements[i].cpf.empty()) cout << d->elements[i].name << " - " << d->elements[i].cpf << " - " << d->elements[i].wasFull << "\n";
        else cout << "--- " << d->elements[i].wasFull << "\n";
    }
}

void remove(Dictionary* d, string k){
    int index = search(d, k);
    if(index!=-1){
        d->elements[index].cpf.clear();
        d->elements[index].name.clear();
    }
}

int main(){

    int n=0;
    int k=0;
    vector<int> perm;
    string comando, nome, cpf;
    cin >> n;
    for(int i=0; i<n-1; i++){
        cin >> k;
        perm.push_back(k);
    }

    Dictionary* d = createDictionaty(n, perm);

    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> comando;
        if(comando=="add"){
            cin >> nome >> cpf;
            insert(d, cpf, nome);
            cout << "\n";
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
