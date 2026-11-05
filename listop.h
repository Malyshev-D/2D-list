#ifndef LISTOPERATIONS
#define LISTOPERATIONS

void ListInit   (list_t* list, int capacity, int size);
void ListAdd    (list_t* list, int value,    int position);
void ListDelete (list_t* list, int position);
int  FindFree   (list_t  list);

#endif
