#include <iostream>
#include "list.h"
#define MAX 10

using namespace std;

typedef struct list{
    int listSize;
    int maxSize;
    int curr;
    int *listArray;
}List;

List* create(){
    List* l = new List;
    l->maxSize=MAX;
    l->listSize=l->curr=0;
    l->listArray=new int;
    return l;
}

void clean(List* l){
    delete(l->listArray);
    l->listArray=NULL;
    delete(l);
    l=NULL;
}

void insert(List* l, int item){
    if(l->listSize>=l->maxSize){
        cout << "The list is full!" << "\n";
    }
    else{
        int i=l->listSize;
        while(i>l->curr){
            l->listArray[i]=l->listArray[i-1];
            i--;
        }
        l->listArray[l->curr]=item;
        l->listSize++;
    }
}

int remove(List* l){
    if(l->curr < 0 || l->curr >= l->listSize){
        printf("List is empty!\n");
    }
    int item = l->listArray[l->curr];
    int i=l->curr;
    while(i<((l->listSize)-1)){
        l->listArray[i]=l->listArray[i+1];
        i++;
    }
    l->listSize--;
    return item;
}

void moveToStart(List* l){
    l->curr=0;
}

void moveToEnd(List* l){
    l->curr=l->listSize;
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

void printList(const List* l){
    cout << "List = <";
    for(int i=0; i<l->listSize-1; i++){
        cout << l->listArray[i] << ", ";
    }
    cout << l->listArray[l->listSize-1] << ">" << "\n";
}

