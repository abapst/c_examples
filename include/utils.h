#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct _list {
    size_t n;
    float *data;
} list;

/* Function declarations */
list *read_list(const char *filename);
list *create_list(size_t n;);
void swap(float *data, int i1, int i2);
list *copy_list(list *src);
int compare_lists(list *src, list *dst);
void delete_list(list *v);
void print_list(list *v);
/*************************/

#endif
