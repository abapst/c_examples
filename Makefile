CC=gcc
CFLAGS=-g -Wall -Werror -Wextra -Wfatal-errors -pedantic-errors
LDFLAGS=
INC=-I./include
VPATH=src/
OBJDIR=obj/
BINDIR=bin/

SINGLEEXEC=\
	fibonacci\
	max_profit\
	permute_string\

MULTIEXEC=\
    sorteval\
    test_fileio\
    test_list\

OBJ=\
	utils.o\
	sortalgs.o\
    heapify.o\
    list.o\
    fileio.o\

SINGLEEXECS=$(addprefix $(BINDIR), $(SINGLEEXEC))
MULTIEXECS=$(addprefix $(BINDIR), $(MULTIEXEC))
OBJS=$(addprefix $(OBJDIR), $(OBJ))
DEPS=$(wildcard include/*.h) Makefile

all: bin obj $(SINGLEEXECS) $(MULTIEXECS)

$(OBJDIR)%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(BINDIR)%: %.c
	$(CC) $(CFLAGS) $^ -o $@

$(BINDIR)sorteval: sorteval.c obj/utils.o obj/sortalgs.o obj/heapify.o
	$(CC) $(CFLAGS) $(INC) $^ -o $@ $(LDFLAGS)

$(BINDIR)test_list: test_list.c obj/list.o
	$(CC) $(CFLAGS) $(INC) $^ -o $@ $(LDFLAGS)

$(BINDIR)test_fileio: test_fileio.c obj/fileio.o obj/list.o
	$(CC) $(CFLAGS) $(INC) $^ -o $@ $(LDFLAGS)

obj:
	mkdir -p obj

bin:
	mkdir -p bin

.PHONY: clean
clean:
	rm -rf *.o core.* bin/ obj/ $(OBJS) $(SINGLEEXECS) $(MULTIEXECS)
