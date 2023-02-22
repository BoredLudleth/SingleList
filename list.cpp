#include "list.hpp"

void list_ctor (struct spis* myList) {
    myList->list = (struct elem*) calloc (LIST_LENGTH,  sizeof (struct elem));
    myList->head = -1;
    myList->tail = 1;
    myList->free = -1;
    myList->length = 0;

    for (int i = 0; i < LIST_LENGTH - 1; i++) {
        myList->list[i].next = - i - 1;
    }

    for (int i = 0; i < LIST_LENGTH; i++) {
        myList->list[i].data = POISON;
    }

    myList->list[LIST_LENGTH - 1].next = 0;
}

void list_dtor (struct spis* myList) {
    myList->head = 0;
    myList->tail = 0;
    myList->free = 0;

    for (int i = 0; i < LIST_LENGTH; i++) {
        myList->list[i].data = POISON;
    }

    free (myList->list);
}

void list_insert_first (struct spis* myList, type value) {
    int freeElem = -myList->free;

    myList->free = myList->list[-myList->free].next;
    myList->list[freeElem].data = value;

    if (myList->length == 0) {
        myList->head = freeElem;
        myList->list[freeElem].next = 0;
        myList->tail = freeElem;
    } else {
        myList->list[freeElem].next = myList->head;
        myList->head = freeElem;
    }

    myList->length += 1;
}

void list_insert_after (struct spis* myList, type value, int index) {
    if (myList->length < index) {
        printf ("We can't add your value\n");
        return;
    }

    int insertBlock = -myList->free;

    myList->free = myList->list[-myList->free].next;

    myList->list[insertBlock].next = myList->list[index].next;
    myList->list[index].next = insertBlock;

    myList->list[insertBlock].data = value;

    myList->length++;
}

void list_insert_last (struct spis* myList, type value) {
    int freeElem = -myList->free;

    myList->free = myList->list[-myList->free].next;
    myList->list[freeElem].data = value;
    myList->list[myList->tail].next = freeElem;

    if (myList->length == 0) {
        myList->head = freeElem;
        myList->list[freeElem].next = 0;
        myList->tail = freeElem;
    } else {
        myList->list[freeElem].next = 0;
        myList->tail = freeElem;
    }

    myList->length += 1;
}

int list_search (struct spis* myList, type value) {
    int current = myList->head;

    while (current != 0 && myList->length != 0) {
        if (myList->list[current].data == value) {
            return current;
        }
        current = myList->list[current].next;
    }

    return -1;
}

void list_dump (struct spis myList) {
    printf ("==========LIST_DUMP==========\n");

    printf ("length: %d\n", myList.length);
    printf ("head: %d\n", myList.head);
    printf ("tail: %d\n", myList.tail);
    printf ("free: %d\n", myList.free);

    printf ("    № data  next\n");

    for (int i = 0; i < LIST_LENGTH; i++) {
        printf ("%5d ", i);
        printf (TYPE_SPECIFICATOR_FIVE, myList.list[i].data);
        printf (" %d\n", myList.list[i].next);
    }

    printf ("HUMAN VIEW\n");

    int current = myList.head;

    while (current != 0 && myList.length != 0) {
        printf (TYPE_SPECIFICATOR, myList.list[current].data);
        printf (" -> ");
        current = myList.list[current].next;
    }

    printf ("end\n=============================\n");
}