#ifndef _LIST_H
#define _LIST_H

typedef struct list List;

List* create();
void clear(List* l);

void insert(List* l, int item);
int remove(List* l);

void moveToStart(List* l);
void moveToEnd(List* l);
void prev(List* l);
void next(List* l);

void printList(const List* l);

#endif
