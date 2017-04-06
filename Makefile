CC = gcc
CFLAGS = -g -O0

all: main

main: main.o trie.o utilitarios.o
	$(CC) $(CFLAGS) main.o trie.o utilitarios.o -o main

main.o: main.c trie.h utilitarios.h
	$(CC) $(CFLAGS) -c main.c

trie.o: trie.c trie.h
	$(CC) $(CFLAGS) -c trie.c

utilitarios.o: utilitarios.c utilitarios.h
	$(CC) $(CFLAGS) -c utilitarios.c

clean:
	rm *.o main