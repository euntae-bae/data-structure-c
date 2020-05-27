#ifndef __LIST_H__
#define __LIST_H__
#include <stdbool.h>

typedef int Data;

typedef struct node {
    Data data;
	struct node *prev;
    struct node *next;
} Node;

typedef struct list {
    Node *head;
    Node *tail;
} List;

List * list_create(void);
void list_destroy(List *l);
bool list_empty(List *l);
void list_push_front(List *l, Data data);
void list_push_back(List *l, Data data);
int list_pop_front(List *l);
int list_pop_back(List *l);
void list_clear(List *l);
Node * list_find(List *l, Data data);

#endif
