CC=gcc
CFLAGS=-g -Wall -Wfatal-errors
LDFLAGS=-pthread
INC=-I./include
VPATH=./src/

EXEC=\
	fibonacci \
    linked_list \
    max_profit \
    merge_sort \
    selection_sort \
    permute_string

all: $(EXEC)

.PHONY: clean
clean:
	rm -rf $(EXEC) core.*
