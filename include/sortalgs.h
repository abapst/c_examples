#ifndef SORTALGS_H
#define SORTALGS_H

#include "utils.h"

#define PARENT(i)    ( (i-1) / 2 )
#define LCHILD(i)    ( 2*i + 1 )
#define RCHILD(i)    ( 2*i + 2 )

typedef void (*sortAlgPtr)(list *src);

/* Function declarations */
void bubble_sort(list *src);
void selection_sort(list *src);
void insertion_sort(list *src);

void quicksort(list *src);
void qsort_main(list *src, int lo, int hi);
int qsort_partition(list *src, int lo, int hi);

void mergesort(list *src);
void TopDownSplitMerge(list *src, int iStart, int iEnd, list *dst);
void TopDownMerge(list *src,int iStart, int iMiddle, int iEnd, list *dst);

void heapsort(list *src);
void heapify(list *src);
void sift_down(list *src, size_t start, size_t end);

#endif /* SORTALGS_H */
