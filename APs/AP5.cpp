#include <iostream>
using namespace std;

typedef struct node{
    int element;
    struct node* next;
}Node;

typedef struct{
    Node* head;
    Node* tail;
    Node* curr;
    int size;
}List;

Node* createNode(int item, Node* next){
    Node* n = new Node;
    n->element = item;
    n->next = next;
    return n;
}

Node* createNode(Node* next){
    Node* n = new Node;
    n->next = next;
    return n;
}

List* createList(int x){
    List* l = new List;
    l->curr = l->head = l->tail = createNode(NULL);
    l->size=0;
    return l;
}

void insert(List* l, int x){
    l->curr->next = createNode(x, l->curr->next);
    if(l->tail==l->curr){
        l->tail =l->curr->next;
    }
    l->size++;
}

void remove(List* l){
    if(l->curr->next!=NULL){
        Node* tmp = l->curr->next;
        if(l->tail==l->curr->next){
            l->tail=l->curr;
        }
        l->curr->next=l->curr->next->next;
        delete(tmp);
        l->size--;
    }
}

void count(const List* l, int x){
    Node* tmp=l->head;
    int count=0;
    while(tmp!=l->tail){
        tmp = tmp->next;
        if(tmp->element==x){
            count++;
        }
    }
    cout << count << "\n";
}

void prev(List* l){
    if(l->curr!=l->head){
        Node* tmp = l->head;
        while(tmp!=l->curr){
            tmp = tmp->next;
        }
        l->curr = tmp;
    }
}

void next(List* l){
    if(l->curr!=l->tail){
        l->curr = l->curr->next;
    }
}

void clear(List* l){
    Node* tmp = l->head;
    Node* next = tmp->next;
    while(tmp!=l->tail){
        next = tmp->next;
        delete(tmp);
        tmp = next;
    }
    delete(tmp);
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
