#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct list_t
{
    int* data;
    int* next;
    int* prev;
    int capacity;
};

#include "graphics.h"
#include "listop.h"

int main()
{
    int capacity = 15;
    int size = 9;
    int dump_num = 0;
    list_t list = {};
    ListInit(&list, capacity, size);

    FILE* file = DumpBegin();

    ListDump(file, list, capacity, &dump_num);
    ListAdd(&list, 35, 3);
    ListDump(file, list, capacity, &dump_num);
    ListDelete(&list, 4);
    ListDump(file, list, capacity, &dump_num);

    DumpEnd(file);

    free(list.data);
    free(list.next);
    free(list.prev);
    return 0;
}
