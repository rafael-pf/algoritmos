#include <iostream>

using namespace std;

typedef struct{
    int max_size;
    int list_size;
    int curr;
    int *array;
} List;

void insert(List *list){

}

void remove(List *list){

}

int count(List *list, int k){
    int count=0;

    

    return count;
}

void prev(List *list){
    if(list->curr != 0){
        list->curr--;
    }
}

void next(List *list){
    if(list->curr < list->list_size){
        list->curr++;
    }
}

int main(){
    


    return 0;
}
