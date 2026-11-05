#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define POISON 0x2DA115FD // 765531645

struct list_t
{
    int* data;
    int* next;
    int* prev;
    int capacity;
};

#include "listop.h"

void ListAdd(list_t* list, int value, int position) // добавление элемента по значению и номеру предыдущего элемента
{
    int free = -1;
    if ((free = FindFree(*list)) == -1)
    {
        printf("All positions are reserved\n");
        return ;
    }
    // надо найти свободный элемент next[i] == -1  и туда вставлять новый
    list->data[free] = value;
    list->prev[list->next[position]] = free;
    list->prev[free] = position;
    list->next[free] = list->next[position];
    list->next[position] = free;
}

int FindFree(list_t list) // (пока такой) поиск свободного места
{
    for (int idx = 1; idx <= list.capacity; idx++)
    {
        if (list.next[idx] == -1)
        {
            return idx;
        }
    }
    return -1;
}

void ListDelete(list_t* list, int position) // удаление элемента по индексу
{
    list->next[list->prev[position]] = list->next[position];
    list->prev[list->next[position]] = list->prev[position];
    list->next[position] = -1;
    list->prev[position] = -1;
}

void ListInit(list_t* list, int capacity, int size) // создание списка
{
    list->data = (int*)calloc(capacity + 1, sizeof(int));
    assert(list->data != 0);
    list->next = (int*)calloc(capacity + 1, sizeof(int));
    assert(list->next != 0);
    list->prev = (int*)calloc(capacity + 1, sizeof(int));
    assert(list->prev != 0);

    list->data[0] = POISON;
    list->next[0] = 0;
    list->prev[0] = 0;
    for (int idx = 1; idx <= capacity; idx++)
    {
        if (idx <= size)
        {
            list->data[idx] = idx * 10;
            list->next[idx] = idx + 1;
            list->prev[idx] = idx - 1;
        }
        else
        {
            list->data[idx] = POISON;
            list->next[idx] = -1;
            list->prev[idx] = -1;
        }
    }
    list->next[size] = 0;
    list->capacity = capacity;
}
