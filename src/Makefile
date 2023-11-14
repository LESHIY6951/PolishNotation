CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

all: 
	$(CC) $(CFLAGS) -c stack.c
	$(CC) $(CFLAGS) -c graph.c
	$(CC) $(CFLAGS) -c structPL.c
	$(CC) $(CFLAGS) -c polish_math.c
	$(CC) $(CFLAGS) -c field.c
	$(CC) $(CFLAGS) -c graph_io.c
	$(CC) $(CFLAGS) *.o -o ../build/graph

clean:
	rm -rf *.o
	rm -rf *.a

rebuild: clean all




