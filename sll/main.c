#include <stdio.h>
#include "List.h"

enum Menu {
    MENU_PUSH_BACK = 1,
    MENU_PUSH_FRONT,
    MENU_POP_BACK,
    MENU_POP_FRONT,
    MENU_FIND,
    MENU_CLEAR_LIST,
    MENU_PRINT_LIST,
    MENU_PRINT_HEAD,
    MENU_PRINT_TAIL,
    MENU_PRINT_MENU,
    MENU_EXIT = 0
};

void printMenu(void) {
    puts("1. push back");
    puts("2. push front");
    puts("3. pop back");
    puts("4. pop front");
    puts("5. find");
    puts("6. clear list");
    puts("7. print list");
    puts("8. print head");
    puts("9. print tail");
    puts("10. show menu");
    puts("0. exit");
}

void printList(List *l) {
    Node *node = l->head;
    while (node) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void errorEmptyList(void) {
    fputs("error: empty list\n", stderr);
}

int main(void)
{
    bool loop = true;
    int sel, data;
    List *list = list_create();
    
    printMenu();
    while (loop) {
        printf("> ");
        scanf("%d", &sel);

        switch (sel) {
        case MENU_PUSH_BACK:
            printf("> ");
            scanf("%d", &data);
            list_push_back(list, data);
            break;
        case MENU_PUSH_FRONT:
            printf("> ");
            scanf("%d", &data);
            list_push_front(list, data);
            break;
        case MENU_POP_BACK:
            if (list_empty(list)) {
                errorEmptyList();
                break;
            }
            data = list_pop_back(list);
            printf("> %d\n", data);
            break;
        case MENU_POP_FRONT:
            if (list_empty(list)) {
                errorEmptyList();
                break;
            }
            data = list_pop_front(list);
            printf("> %d\n", data);
            break;
        case MENU_FIND:
            if (list_empty(list)) {
                errorEmptyList();
                break;
            }
            printf("> ");
            scanf("%d", &data);
            Node *node = list_find(list, data);
            if (node)
                printf("> %d\n", node->data);
            else
                printf("> can't find [%d]\n", data);
            break;
        case MENU_CLEAR_LIST:
            list_clear(list);
            break;
        case MENU_PRINT_LIST:
            printList(list);
            break;
        case MENU_PRINT_HEAD:
            printf("> ");
            if (!list_empty(list))
                printf("%d\n", list->head->data);
            else
                printf("NULL\n");
            break;
        case MENU_PRINT_TAIL:
            printf("> ");
            if (!list_empty(list))
                printf("%d\n", list->tail->data);
            else
                printf("NULL\n");
            break;
        case MENU_PRINT_MENU:
            printMenu();
            break;
        case MENU_EXIT:
            loop = false;
            break;
        }
        puts("");
    }

    list_destroy(list);    
    return 0;
}
