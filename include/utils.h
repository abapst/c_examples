#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>

typedef struct _list {
    size_t n;
    float *data;
} list;

/* Function declarations */
list *read_list(const char *filename);
list *create_list(size_t n);
void swap(list *src, int i1, int i2);
int copy_list(list *src, list *dst);
int compare_lists(list *src, list *dst);
void delete_list(list *src);
void print_list(list *src);

void heapify(list *src);
void max_heapify(list *src, size_t ii);
void sift_down(list *src, size_t start, size_t end);

double get_time_sec();
/*************************/

#endif
