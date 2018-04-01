#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "sortalgs.h"

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "Usage: ./test_sort <filename> <algorithm>\n");
        return -1;
    }


    char *filename = argv[1];
    char *alg = argv[2];

    sortAlgPtr algPtr;
    if (!strcmp(alg, "bubble"))
        algPtr = &bubble_sort;
    else if (!strcmp(alg, "selection"))
        algPtr = &selection_sort;
    else if (!strcmp(alg, "insertion"))
        algPtr = &insertion_sort;
    else if (!strcmp(alg, "quick"))
        algPtr = &quicksort;
    else if (!strcmp(alg, "merge"))
        algPtr = &mergesort;
    else if (!strcmp(alg, "heap"))
        algPtr = &heapsort;
    else {
        fprintf(stderr, "'%s' not a valid algorithm!\n", alg);
        return -1;
    }

    list *unsorted;
    unsorted = read_list(filename);
    fprintf(stderr,"UNSORTED:\n");
    fprintf(stderr,"---------\n");
    print_list(unsorted);
    (*algPtr)(unsorted);
    fprintf(stderr,"\nSORTED:\n");
    fprintf(stderr,"-------\n");
    print_list(unsorted);

    free(unsorted);

    return 0;
}
