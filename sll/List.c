#include "List.h"
#include <stdio.h>
#include <stdlib.h>


List * list_create(void) {
    List *list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void list_destroy(List *l) {
    if (l) {
        list_clear(l);
        free(l);
        l = NULL;
    }
}

bool list_empty(List *l) {
    return !(l->head);
}

void list_push_front(List *l, Data data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;

    if (!l->head) {
        node->next = NULL;
        l->head = node;
        l->tail = l->head;
    }
    else {
        node->next = l->head;
        l->head = node;
    }
}

void list_push_back(List *l, Data data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if (!l->head) {
        l->head = node;
        l->tail = l->head;
    }
    else {
        l->tail->next = node;
        l->tail = node;
    }
}

int list_pop_front(List *l) {
    int retData = l->head->data;
    Node *next = l->head->next;
    free(l->head);
    l->head = next;
    if (!next)
        l->tail = NULL;
    return retData;
}

int list_pop_back(List *l) {
    int retData = l->tail->data;
    if (!l->head->next) { // l->head == l->tail
        free(l->tail);
        l->head = NULL;
        l->tail = NULL;
        return retData;
    }

    Node *prev = l->head;
    while (prev->next != l->tail) {
        prev = prev->next;
    }
    free(l->tail);
    prev->next = NULL;
    l->tail = prev;
    return retData;
}

void list_clear(List *l) {
    while (l->head) {
        list_pop_front(l);
    }
}

Node * list_find(List *l, Data data) {
    Node *node = l->head;
    while (node) {
        if (node->data == data)
            break;
        node = node->next;
    }
    return node;
}