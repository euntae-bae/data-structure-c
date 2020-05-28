#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdbool.h>
#define BUF_SIZE 255

typedef int Data;

typedef struct Queue
{
	Data *arr;
	int front;
	int rear;
} Queue;

Queue * queue_create(void);
void queue_destroy(Queue *q);
void queue_push(Queue *q, Data data);
Data queue_pop(Queue *q);
Data queue_peek(Queue *q);
void queue_clear(Queue *q);
bool queue_empty(Queue *q);
bool queue_full(Queue *q);

int nextIdx(int idx);

#endif
