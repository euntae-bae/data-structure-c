#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

enum Menu {
    MENU_PUSH = 1,
    MENU_POP,
    MENU_PEEK,
    MENU_CLEAR_STACK,
    MENU_PRINT_STACK,
    MENU_PRINT_MENU,
    MENU_EXIT = 0
};

void printMenu(void) {
    puts("1. push");
    puts("2. pop");
	puts("3. peek");
    puts("4. clear stack");
    puts("5. print stack");
    puts("6. print menu");
    puts("0. exit");
}

void printStack(Stack *s) {
	if (stack_empty(s)) {
		printf("(empty)\n");
		return;
	}

	int i;
	for (i = 0; i <= s->top; i++) {
		printf("%d ", s->arr[i]);
	}
	printf("\n");
}

void errorEmptyStack(void) {
    fputs("error: empty stack\n", stderr);
}

void errorFullStack(void) {
	fputs("error: stack full\n", stderr);
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
	Stack *stack = stack_create();
    
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
			if (stack_full(stack)) {
				errorFullStack();
				break;
			}
            printf("> ");
#ifdef READ_FILE
			fscanf(fp, "%d", &data);
#else
            scanf("%d", &data);
#endif
			stack_push(stack, data);
            break;
		case MENU_POP:
			if (stack_empty(stack)) {
				errorEmptyStack();
				break;
			}
			printf("> %d\n", stack_pop(stack));
			break;
		case MENU_PEEK:
			if (stack_empty(stack)) {
				errorEmptyStack();
				break;
			}
			printf("> %d\n", stack_peek(stack));
			break;
		case MENU_CLEAR_STACK:
			stack_clear(stack);
			break;
		case MENU_PRINT_STACK:
			printStack(stack);
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

    stack_destroy(stack);
#ifdef READ_FILE
	fclose(fp);
#endif
    return 0;
}
