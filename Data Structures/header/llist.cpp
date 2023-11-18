#include <iostream>

using namespace std;

typedef struct node{
    int item;
    struct node* next;
}Node;

typedef struct{
    Node* head;
    Node* curr;
    Node* tail;
    int size;
}List;

Node* createNode(int element, Node* next){
    Node* n = new Node;
    n->item = element;
    n->next = next;
    return n;
}

Node* createNode(Node* next){
    Node* n = new Node;
    n->next = next;
    return n;
}

List* createList(){
    List* l = new List;
    l->curr = l->head = l->tail = createNode(NULL);
    l->size = 0;    
    return l;
}

void clean(List* l){
    Node* tmp = l->head;
    Node* next;
    while(tmp->next!=NULL){
        next = tmp->next;
        delete(tmp);
        tmp = next;
    }
    delete tmp;
    delete l;
}

void insert(List* l, int item){
    l->curr->next = createNode(item, l->curr->next);
    if(l->curr==l->tail){
        l->tail=l->curr->next;
    }
    l->size++;
}

int remove(List* l){
    if(l->curr->next==NULL){
        return -1;
    }
    int item = l->curr->next->item;
    Node* tmp = l->curr->next;
    if(l->tail=l->curr->next){
        l->tail=l->curr;
    }
    l->curr->next=l->curr->next->next;
    delete tmp;
    l->size--;
    return item;
}

void moveToStart(List* l){
    l->curr = l->head;
}

void prev(List* l){
    if(l->curr!=l->head){
        Node* tmp = l->head;
        while(tmp->next!=l->curr){
            tmp = tmp->next;
        }
        l->curr = tmp;
    }
}

void next(List* l){
    if(l->curr!=l->tail){
        l->curr=l->curr->next;
    }
}

void printList(const List* l){
    if(l->size==0 || l==NULL){
        cout << "List is empty!" << "\n";
    }
    else{
        Node* tmp = l->head;
        cout << "List = <";
        while(tmp->next->next!=NULL){
            cout << tmp->next->item << ", ";
            tmp = tmp->next; 
        }
        cout << tmp->next->item << ">" << "\n";
    }
}
