#ifndef __STACK_H__
#define __STACK_H__

#include <stdbool.h>
#define BUF_SIZE 255

typedef int Data;

typedef struct Stack
{
	Data *arr;
	int top;
} Stack;

Stack * stack_create(void);
void stack_destroy(Stack *s);
void stack_push(Stack *s, Data data);
Data stack_pop(Stack *s);
Data stack_peek(Stack *s);
void stack_clear(Stack *s);
bool stack_empty(Stack *s);
bool stack_full(Stack *s);

#endif
