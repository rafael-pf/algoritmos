#include <iostream>
#include "llist.cpp"

using namespace std;

int main(){

    List* l = createList();
    insert(l, 5);
    printList(l);
    insert(l, 6);
    printList(l);
    insert(l, 7);
    printList(l);
    next(l);
    cout << "Removed item: " << remove(l) << "\n";
    printList(l);
    cout << "Removed item: " << remove(l) << "\n";
    prev(l);
    cout << "Removed item: " << remove(l) << "\n";
    printList(l);

    return 0;
}
