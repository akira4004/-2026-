CC = gcc
CFLAGS = -Wall -Wextra

all: p1 p2 p3

p1: p1.c
	$(CC) $(CFLAGS) -o p1 p1.c

p2: p2.c
	$(CC) $(CFLAGS) -o p2 p2.c

p3: p3.c
	$(CC) $(CFLAGS) -o p3 p3.c

clean:
	rm -f p1 p2 p3

.PHONY: all clean
