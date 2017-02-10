#ifndef __SORTALGS_H__
#define __SORTALGS_H__

#include "utils.h"

/* Function declarations */
void selection_sort(list *src);
list *merge_sort(list *src);
void TopDownSplitMerge(list *src, int iStart, int iEnd, list *dst);
void TopDownMerge(list *src,int iStart, int iMiddle, int iEnd, list *dst);
/*************************/

#endif
