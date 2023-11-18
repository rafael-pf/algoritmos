#include <iostream>
#include "list.h"

using namespace std;

int main(){

    List* l = create();
    insert(l, 5);
    insert(l, 7);
    insert(l, 9);
    printList(l);


    return 0;
}
