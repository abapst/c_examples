#ifndef __SORTALGS_H__
#define __SORTALGS_H__

#include "utils.h"

/* Function declarations */
void bubble_sort(list *src);
void selection_sort(list *src);
void insertion_sort(list *src);

void quicksort(list *src);
void qsort_main(list *src, int lo, int hi);
int qsort_partition(list *src, int lo, int hi);

void mergesort(list *src, list *dst);
void TopDownSplitMerge(list *src, int iStart, int iEnd, list *dst);
void TopDownMerge(list *src,int iStart, int iMiddle, int iEnd, list *dst);
/*************************/

#endif
