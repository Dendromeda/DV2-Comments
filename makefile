CC = gcc -std=c99
CFLAGS = -g -fno-omit-frame-pointer -Wall -Wextra

.PHONY: all
all: cleanComments

cleanComments: cleanComments.o
	$(CC) $(CFLAGS) -o $@ cleanComments.o

cleanComments.o: cleanComments.c
	$(CC) $(CFLAGS) -c cleanComments.c

.PHONY: clean
clean:
	rm -fv *.o cleanComments
