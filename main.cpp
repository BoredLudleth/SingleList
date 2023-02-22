#include "list.hpp"

int main () {
    struct spis myList = {};

    list_ctor (&myList);
    list_dump (myList);
    list_insert_first (&myList, 1);
    list_dump (myList);
    list_insert_last (&myList, 2);
    list_dump (myList);
    list_insert_first (&myList, 3);
    list_dump (myList);
    list_insert_last (&myList, 4);
    list_dump (myList);
    list_insert_after (&myList, 10, 1);
    list_dump (myList);
    list_insert_after (&myList, 13, list_search(&myList, 10));
    list_dump (myList);
    list_dtor (&myList);

    return 0;
}