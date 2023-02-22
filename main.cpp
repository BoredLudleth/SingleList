#include "list.hpp"

int main () {
    struct spis myList = {};

    int command = -1;
    type push_value = 0;
    type search_value = 0;
    int index = 0;

    list_ctor (&myList); 
    printf ("henlo, it's menu for queue\n");
    printf ("1 num - push first at list\n");
    printf ("2 num - push last at lis\n");
    printf ("3 num index - push after index in list\n");
    printf ("4 - list dump\n");
    printf ("5 - list delete next\n");
    printf ("6 - list search\n");
    printf ("7 - menu\n");
    printf ("8 - quit\n");

    while (!scanf_check(scanf("%d", &command)));

    while (command != 0) {
        switch (command) {
            case 1:
                if (!scanf_check (scanf (TYPE_SPECIFICATOR, &push_value))) {
                    break;
                }

                list_insert_first (&myList, push_value);
                break;

            case 2:
                if (!scanf_check (scanf (TYPE_SPECIFICATOR, &push_value))) {
                    break;
                }

                list_insert_last (&myList, push_value);
                break;

            case 3:
                if (!scanf_check (scanf (TYPE_SPECIFICATOR, &push_value))) {
                    break;
                }

                if (!scanf_check (scanf ("%d", &index))) {
                    break;
                }

                list_insert_after (&myList, push_value, index);
                break;

            case 4:
                list_dump (myList);
                break;

            case 5:
                if (!scanf_check (scanf ("%d", &index))) {
                    break;
                }

                list_delete_next (&myList, index);
                break;

            case 6:
                if (!scanf_check (scanf (TYPE_SPECIFICATOR, &search_value))) {
                    break;
                }
                printf ("index of ");
                printf (TYPE_SPECIFICATOR, search_value);
                printf (" is %d\n",list_search (&myList, search_value));
                break;
            case 7:
                printf ("\n1 num - push first at list\n");
                printf ("2 num - push last at lis\n");
                printf ("3 num index - push after index in list\n");
                printf ("4 - list dump\n");
                printf ("5 - list delete next\n");
                printf ("6 - list search\n");
                printf ("7 - menu\n");
                printf ("8 - quit\n");
                break;

            case 8:
                list_dtor (&myList);
                return 0;
                break;
            default:
                printf ("Undefined command\n");
                break;
        }

        if (list_dump(myList) != 0) {
            list_dtor (&myList);
            break;
        }
        
        while (!scanf_check(scanf("%d", &command)));
    }

    return 0;
}
// add menu, delete and check
