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
    Link* n;
    n->element=k;
    n->next = nextval;
    return n;
}

Link* create_link(Link *nextval){
    Link* n;
    n->next=nextval;
    return n;
}

List create_list(){
    List l;
    l.head = l.curr = l.tail = create_link(NULL);
    l.cnt=0;
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
        if(l->tail==l->curr->next){
            l->tail=l->curr;
        }
        l->curr->next= l->curr->next->next;
        l->cnt--; 
    }
}

void moveToStart(List* l){
    l->curr=l->head;
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

void prev(List *l){
    if(l->curr!=l->tail){
        l->curr = l->curr->next;
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
