CC=gcc
CFLAGS=-g -Wall -Wfatal-errors
LDFLAGS=
INC=-I./include
VPATH=./src

ONEEXEC=\
	fibonacci\
	linked_list\
	max_profit\
	permute_string\

MULTIEXEC=\
	sorteval

OBJS=\
	utils.o\
	sortalgs.o\
    heapify.o\

DEPS=\
	include/utils.h\
	include/sortalgs.h\
    include/heapify.h\

all: $(ONEEXEC) $(MULTIEXEC)

$(MULTIEXEC):  sorteval.c $(OBJS)
	$(CC) $(CFLAGS) $(INC) $^ -o $@ $(LDFLAGS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

.PHONY: clean

clean:
	rm -rf *.o core.* $(ONEEXEC) $(MULTIEXEC)
