#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

enum Menu {
    MENU_PUSH = 1,
    MENU_POP,
    MENU_PEEK,
    MENU_CLEAR_QUEUE,
    MENU_PRINT_QUEUE,
    MENU_PRINT_MENU,
    MENU_EXIT = 0
};

void printMenu(void) {
    puts("1. push");
    puts("2. pop");
	puts("3. peek");
    puts("4. clear queue");
    puts("5. print queue");
    puts("6. print menu");
    puts("0. exit");
}

void printQueue(Queue *q) {
	if (queue_empty(q)) {
		printf("(empty)\n");
		return;
	}

	int i = nextIdx(q->front);;

	do {
		printf("%d ", q->arr[i]);
		i = nextIdx(i);
	} while (i != nextIdx(q->rear));
	printf("\n");
}

void errorEmptyQueue(void) {
    fputs("error: empty queue\n", stderr);
}

void errorFullQueue(void) {
	fputs("error: queue full\n", stderr);
}

int main(void)
{
#ifdef READ_FILE
	FILE *fp = fopen("input.txt", "rt");
	if (!fp) {
		fputs("error: failed to open file [input.txt]\n", stderr);
		exit(1);
	}
#endif

    bool loop = true;
    int sel, data;
	Queue *queue = queue_create();
    
    printMenu();
    while (loop) {
        printf("> ");
#ifdef READ_FILE
		fscanf(fp, "%d", &sel);
#else
        scanf("%d", &sel);
#endif

        switch (sel) {
		case MENU_PUSH:
			if (queue_full(queue)) {
				errorFullQueue();
				break;
			}
            printf("> ");
#ifdef READ_FILE
			fscanf(fp, "%d", &data);
#else
            scanf("%d", &data);
#endif
			queue_push(queue, data);
            break;
		case MENU_POP:
			if (queue_empty(queue)) {
				errorEmptyQueue();
				break;
			}
			printf("> %d\n", queue_pop(queue));
			break;
		case MENU_PEEK:
			if (queue_empty(queue)) {
				errorEmptyQueue();
				break;
			}
			printf("> %d\n", queue_peek(queue));
			break;
		case MENU_CLEAR_QUEUE:
			queue_clear(queue);
			break;
		case MENU_PRINT_QUEUE:
			printQueue(queue);
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

    queue_destroy(queue);
#ifdef READ_FILE
	fclose(fp);
#endif
    return 0;
}
