all: stack fstack

stack: main.c Stack.c Stack.h
	gcc -o stack main.c Stack.c

fstack: main.c Stack.c Stack.h
	gcc -o fstack -D READ_FILE main.c Stack.c

clean:
	rm stack fstack

