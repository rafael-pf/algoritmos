#include <iostream>

using namespace std;

typedef struct node{
    int element;
    struct node *next;
}Node;

typedef struct{
    int size;
    Node* rear;
    Node* front;
}Queue;

Node* createNode(Node* next){
    Node* n = new Node;
    n->next=next;
    return n;
}

Node* createNode(int item, Node* next){
    Node* n = new Node;
    n->element=item;
    n->next=next;
    return n;
}

Queue* createQueue(){
    Queue* q = new Queue;
    q->front = q->rear = createNode(NULL);
    q->size=0;
    return q;
}

void enqueue(Queue* q, int item){
    q->rear->next = createNode(item, NULL);
    q->rear=q->rear->next;
    q->size++;
}

void dequeue(Queue* q){
    if(q->size!=0){
        Node* tmp = q->front->next;
        q->front->next = q->front->next->next;
        if(q->front->next==NULL){
            q->rear=q->front;
        }
        delete(tmp);
        q->size--;
    }
}

int main(){
    


    return 0;
}
