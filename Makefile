CC=clang #use clang by default, just convenience

WARNINGS=-Wall -Wextra -pedantic -Werror

DEBUGFLAGS=-g -ftrapv 

CFLAGS=$(WARNINGS) $(DEBUGFLAGS) --std=c90

OBJECTS=main.o config.o ipc.o 

i3helper: $(OBJECTS)
	$(CC) $(CFLAGS) -o i3helper $(OBJECTS) 

main.o: main.c
	$(CC) $(CFLAGS) -c -o main.o main.c

config.o: config.c config.h
	$(CC) $(CFLAGS) -c -o config.o config.c

ipc.o: ipc.c ipc.h i3/ipc.h
	$(CC) $(CFLAGS) -c -o ipc.o ipc.c
