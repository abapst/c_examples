CC=/usr/bin/gcc
CFLAGS=-g -Wall -Wextra -Wfatal-errors -pedantic-errors -std=c99
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
    test_parse\
	test_sort\

OBJ=\
	utils.o\
	sortalgs.o\
    linked_list.o\
    fileio.o\
    parse.o\

SINGLEEXECS=$(addprefix $(BINDIR), $(SINGLEEXEC))
MULTIEXECS=$(addprefix $(BINDIR), $(MULTIEXEC))
OBJS=$(addprefix $(OBJDIR), $(OBJ))
DEPS=$(wildcard include/*.h) Makefile

all: bin obj $(SINGLEEXECS) $(MULTIEXECS)

$(OBJDIR)%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(BINDIR)%: %.c
	$(CC) $(CFLAGS) $^ -o $@

$(BINDIR)sorteval: sorteval.c obj/utils.o obj/sortalgs.o
	$(CC) $(CFLAGS) $(INC) $^ -o $@ $(LDFLAGS)

$(BINDIR)test_list: test/test_list.c obj/linked_list.o
	$(CC) $(CFLAGS) $(INC) $^ -o $@ $(LDFLAGS)

$(BINDIR)test_fileio: test/test_fileio.c obj/fileio.o obj/linked_list.o
	$(CC) $(CFLAGS) $(INC) $^ -o $@ $(LDFLAGS)

$(BINDIR)test_parse: test/test_parse.c obj/parse.o
	$(CC) $(CFLAGS) $(INC) $^ -o $@ $(LDFLAGS)

$(BINDIR)test_sort: test/test_sort.c obj/utils.o obj/sortalgs.o
	$(CC) $(CFLAGS) $(INC) $^ -o $@ $(LDFLAGS)

obj:
	mkdir -p obj

bin:
	mkdir -p bin

.PHONY: clean
clean:
	rm -rf *.o core.* bin/ obj/ $(OBJS) $(SINGLEEXECS) $(MULTIEXECS)
