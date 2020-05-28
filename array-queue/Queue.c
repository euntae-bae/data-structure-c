#include <stdlib.h>
#include "Queue.h"

Queue * queue_create(void) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->arr = (Data*)malloc(sizeof(Data) * BUF_SIZE);
    q->front = 0;
    q->rear = 0;
    return q;
}

void queue_destroy(Queue *q) {
    if (q->arr)
        free(q->arr);
    free(q);
}

void queue_push(Queue *q, Data data) {
    q->rear = nextIdx(q->rear);
    q->arr[q->rear] = data;
}

Data queue_pop(Queue *q) {
    q->front = nextIdx(q->front);
    return q->arr[q->front];
}

Data queue_peek(Queue *q) {
    return q->arr[nextIdx(q->front)];
}

void queue_clear(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

bool queue_empty(Queue *q) {
    return (q->front == q->rear);
}

bool queue_full(Queue *q) {
    return (nextIdx(q->rear) == q->front);
}

int nextIdx(int idx) {
    if (idx + 1 == BUF_SIZE)
        return 0;
    else
        return idx + 1;
}