#include <iostream>
#include "list.h"

using namespace std;

int main(){

    List* l = create();
    insert(l, 5);
    insert(l, 7);
    insert(l, 9);
    printList(l);
    prev(l);
    cout << "Removed item: " << remove(l) << "\n";
    printList(l);
    moveToStart(l);
    insert(l, 0);
    printList(l);
    moveToEnd(l);
    insert(l, 1);
    printList(l);


    return 0;
}
