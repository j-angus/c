
CC = gcc
CFLAGS = -g -Wall -std=c99 -pedantic
FILE = filename

$(FILE): $(FILE).o char_ops.o 
	$(CC) $(CFLAGS) -o $(FILE)~ $(FILE).o char_ops.o

$(FILE).o: $(FILE).c char_ops.h
	$(CC) $(CFLAGS) -c $(FILE).c

char_ops.o: char_ops.c char_ops.h
	$(CC) $(CFLAGS) -c char_ops.c
