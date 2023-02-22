#ifndef LIST_HPP
#define LIST_HPP

#include <stdlib.h>
#include <stdio.h>

#define DBG printf("FILE:%s FUNC:%s LINE:%d\n", __FILE__, __PRETTY_FUNCTION__, __LINE__);

typedef int type;
#define TYPE_SPECIFICATOR "%d"
#define TYPE_SPECIFICATOR_FIVE "%5d"
#define LIST_LENGTH 10
#define POISON 0xDEAD

struct elem {
    type data;
    int next;
};

struct spis {
    struct elem* list;
    int head;
    int tail;
    int free;
    int length;
};

void list_ctor (struct spis* myList);

void list_dtor (struct spis* myList);

void list_insert_first (struct spis* myList, type value);

void list_insert_after (struct spis* myList, type value, int index);

void list_insert_last (struct spis* myList, type value);

void list_dump (struct spis myList);

int list_search (struct spis* myList, type value);
#endif