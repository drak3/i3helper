CC=clang #use clang by default, just convenience

WARNINGS=-Wall -Wextra -pedantic -Werror

DEBUGFLAGS=-g -ftrapv 

CFLAGS=$(WARNINGS) $(DEBUGFLAGS) --std=c90

i3helper: main.o
	$(CC) $(CFLAGS) -o i3helper main.o

main.o: main.c
	$(CC) $(CFLAGS) -c -o main.o main.c
