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
        myList->list[i].next = POISON;
    }

    free (myList->list);
    myList->list = nullptr;
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
    if (myList->length < index || index < 0) {
        printf ("We can't add your value\n");
        myList->errors = INSERT_ERROR;
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

    while (current > 0 && myList->length != 0) {
        if (myList->list[current].data == value) {
            return current;
        }
        current = myList->list[current].next;
    }

    return -1;
}

int  list_delete_next (struct spis* myList, type index) {
    if (myList->list[index].next == 0 || myList->length < index) {
        printf("You can't delete unexisting thing(\n");
        myList->errors = DELETE_ERROR;
        return 0;
    }

    int delValue = myList->list[myList->list[index].next].data;

    myList->list[myList->list[index].next].data = POISON;
    int next_addr = myList->list[myList->list[index].next].next;
    myList->list[myList->list[index].next].next = myList->free;
    myList->free = myList->list[index].next;
    myList->list[index].next = next_addr;

    printf ("DELETED VALUE: %d\n", delValue);
    return 1;

}

int list_dump (struct spis myList) {
    printf ("==========LIST_DUMP==========\n");

    printf ("ERRORS: %d\n", myList.errors);

    switch (myList.errors) {
        case NO_ERRORS:
            printf ("NO PROBLEMS\n");
            break;
        case INSERT_ERROR:
            printf ("INSERT ERROR\n");
            break;
        case DELETE_ERROR:
            printf ("DELETE PROBLEM\n");
            break;
        default:
            printf ("LIST DEFENDER WAS HAHAcked\n");
            break;
    };

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

    return myList.errors;
}

int scanf_check (int x) {
    if (x == 0) {
        printf ("Undefined command\n");
        while (getchar() != '\n');

        return 0;
    }

    return 1;
}
