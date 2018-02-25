CC = gcc -std=c99
CFLAGS = -g -fno-omit-frame-pointer -Wall -Wextra

.PHONY: all
all: removeComments
removeComments: removeComments.o
	$(CC) $(CFLAGS) -o $@ removeComments.o

removeComments.o: removeComments.c
	$(CC) $(CFLAGS) -c removeComments.c

.PHONY: clean
clean:
	rm -fv *.o removeComments
