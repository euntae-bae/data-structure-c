#include "Stack.h"
#include <stdlib.h>

Stack * stack_create(void) {
	Stack *s = (Stack*)malloc(sizeof(Stack));
	s->arr = (Data*)malloc(sizeof(Data) * BUF_SIZE);
	s->top = -1;
	return s;
}

void stack_destroy(Stack *s) {
	if (s->arr)
		free(s->arr);
	free(s);
}

void stack_push(Stack *s, Data data) {
	s->arr[++(s->top)] = data;
}

Data stack_pop(Stack *s) {
	return s->arr[(s->top)--];
}

Data stack_peek(Stack *s) {
	return s->arr[s->top];
}

void stack_clear(Stack *s) {
	s->top = -1;
}

bool stack_empty(Stack *s) {
	return (s->top == -1);
}

bool stack_full(Stack *s) {
	return (s->top == BUF_SIZE - 1);
}
