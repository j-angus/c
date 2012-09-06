
PROJ = co_tst_drv~
OBJS = co_tst_drv.o char_ops.o

CC = gcc
CFLAGS = -g -Wall -std=c99 -pedantic

$(PROJ): $(OBJS)
	$(CC) $(CFLAGS) -o $(PROJ) $(OBJS)

$(OBJS): char_ops.h
