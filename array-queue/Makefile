queue: Queue.c Queue.h main.c
	gcc -o queue Queue.c main.c

fqueue: Queue.c Queue.h main.c
	gcc -o fqueue -D READ_FILE Queue.c main.c

all: queue fqueue

clean:
	rm queue fqueue