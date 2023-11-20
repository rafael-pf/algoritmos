#include <iostream>
using namespace std;

typedef struct node{
    int element;
    struct node* next;
}Node;

typedef struct{
    Node* top;
    int size;
}Stack;

Node* createNode(int item, Node* next){
    Node* n =  new Node;
    n->element=item;
    n->next=next;
    return n;
}

Stack* createStack(){
    Stack* s = new Stack;
    s->top=NULL;
    s->size=0;
    return s;
}

void push(Stack* s, int item){
    s->top = createNode(item, s->top);
    s->size++;
}

void pop(Stack* s, int n){
    int soma=0;
    for(int i=0; i<n; i++){
        soma+=s->top->element;
        if(s->top!=NULL){
            Node* tmp = s->top;
            s->top=s->top->next;
            delete(tmp);
            s->size--;
        }
    }
    cout << soma << "\n";
}

void clear(Stack* s){
    Node* tmp = s->top;
    Node* next = tmp->next;
    while (tmp!=NULL){
        next = tmp->next;
        delete(tmp);
        tmp = next;
    }
    delete(tmp);
    delete(s);
}

int main(){
    int c=0, x=0;
    string comando;
    cin >> c;
    for(int i=0; i<c; i++){
        Stack* stack = createStack();
        cin >> comando;
        while(comando!="end"){
            if(comando=="push"){
                cin >> x;
                push(stack, x);
            }
            else if(comando=="pop"){
                cin >> x;
                pop(stack, x);
            }
            cin >> comando; 
        }
        //clear(stack);
    }

    return 0;
}
