#include <iostream>

typedef struct node{
    char element;    
    struct node* next;
}Node;

typedef struct{
    Node* top;
    int size;
}Stack;

Node* createNode(char item, Node* next){
    Node* n = new Node;
    n->element = item;
    n->next = next;
    return n;
}

Stack* createStack(){
    Stack* s = new Stack;
    s->top = NULL;
    s->size=0;
    return s;
}

void push(Stack* s, char item){
    s->top = createNode(item, s->top);
    s->size++;
}

void pop(Stack* s){
    s->top = s->top->next;
    
}

int main(){
    
    
    
    

    return 0;
}
