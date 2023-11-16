#include <iostream>

using namespace std;

typedef struct{
    int maxSize;
    int listSize;
    int curr;
    int* list_array;
} List;

List create_list(int size){
    List l;
    l.maxSize = size;
    l.listSize = 0;
    l.curr = 0;
    l.list_array = new int[size];
    return l;
}

void insert(List* l, int k){
    if((*l).listSize > (*l).maxSize){
        printf("Lista cheia!\n");
    }
    else{
        int i=(*l).listSize;
        while(i>(*l).curr){
            (*l).list_array[i]=(*l).list_array[i-1];
            i--;
        }
        (*l).list_array[(*l).curr]=k;
        (*l).listSize++;
    }
}

void remove(List* l){
    if((*l).curr<0 || (*l).curr >= (*l).listSize){
        printf("Erro!\n");
    }
    else{
        int i=(*l).curr;
        while(i<(*l).listSize-1){
            (*l).list_array[i]=(*l).list_array[i+1];
            i++;
        }
        (*l).listSize--;
    }
}

void moveToStart(List* l){
    (*l).curr = 0;
}

void moveToEnd(List* l){
    (*l).curr = (*l).listSize;
}

void prev(List* l){
    if((*l).curr!=0){
        (*l).curr--;
    }
}

void next(List* l){
    if((*l).curr<(*l).listSize){
        (*l).curr++;
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
