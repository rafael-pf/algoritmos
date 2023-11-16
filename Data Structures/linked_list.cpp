#include <iostream>

using namespace std;

typedef struct{
    int element;
    Link* next;
}Link;

typedef struct{
    Link* head;
    Link* tail;
    Link* curr;
    int cnt;
}List;

Link* create_link(int k, Link *nextval){
    Link* n = new Link;
    n->element=k;
    n->next = nextval;
    return n;
}

Link* create_link(Link *nextval){
    Link* n = new Link;
    n->next=nextval;
    return n;
}

List* create_list(){
    List* l = new List;
    l->head = l->curr = l->tail = create_link(NULL);
    l->cnt=0;
    return l;
}

void insert(List* l, int k){
    l->curr->next = create_link(k, l->curr->next);
    if(l->tail == l->curr){
        l->tail = l->curr->next;
    }
    l->cnt++;
}

void remove(List* l){
    if(l->curr->next==NULL){
        printf("Erro!\n");
    }
    else{
        Link *tmp = l->curr->next;
        if(l->tail==l->curr->next){
            l->tail=l->curr;
        }
        l->curr->next= l->curr->next->next;
        delete tmp;
        l->cnt--;
    }
}

void moveToStart(List* l){
    l->curr=l->head;
}

void moveToEnd(List* l){
    l->curr=l->tail;
}

void prev(List* l){
    if(l->curr==l->head){
        printf("Erro!\n");
    }
    Link* temp=l->head;
    while(temp->next!=l->curr){
        temp = temp->next;
    }
    l->curr=temp;
}

void next(List *l){
    if(l->curr!=l->tail){
        l->curr = l->curr->next;
    }
}

void delete_list(List *l){
    Link* tmp = l->head;
    Link* next = tmp->next;
    while(tmp->next!=NULL){
        next = tmp->next;
        delete tmp;
        tmp = next;
    }
    delete tmp;
    delete l;
}

void print_list(List *l){
    Link *tmp = l->head;
    while(tmp->next !=  NULL){
        cout << tmp->next->value << endl;
        tmp = tmp->next;
    }
}

int main(){

    int comando;
    
    while(comando != 7){
        cin >> comando;
        printf("==========MENU=========\n");
        printf("[1] - Insert\n");
        printf("[2] - Remove\n");
        printf("[3] - MoveToStart\n");
        printf("[4] - MoveToEnd\n");
        printf("[5] - Prev\n");
        printf("[6] - Next\n");
        printf("[7] - Exit\n");
    }


    return 0;
}
