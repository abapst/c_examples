#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdlib.h>
#include <stdio.h>
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

double get_time_ms();
/*************************/

#endif
