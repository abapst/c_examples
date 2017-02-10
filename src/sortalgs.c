#include "sortalgs.h"


void selection_sort(list *src)
{
    int ii,jj;
    int iMin;
  
    for(jj = 0; jj < src->n; jj++) {
      iMin = jj;
      for(ii=jj+1; ii < src->n; ii++) {
        if (src->data[ii] < src->data[iMin])
          iMin = ii;
      }

      if (iMin != jj)
        swap(src->data, iMin, jj);
    }
}

list *merge_sort(list *src)
{
    list *dst = copy_list(src);
    TopDownSplitMerge(src, 0, src->n, dst);

    return dst;
}

void TopDownSplitMerge(list *src, int iStart, int iEnd, list *dst)
{
  int iMiddle;
  if (iEnd - iStart < 2) return;

  iMiddle = (iEnd + iStart) / 2;
  /* Alternating the merge direction with each level of recursion is
     a trick to avoid the copy-back step */
  TopDownSplitMerge(dst, iStart, iMiddle, src);
  TopDownSplitMerge(dst, iMiddle, iEnd, src);

  TopDownMerge(src, iStart, iMiddle, iEnd, dst);
}

void TopDownMerge(list *src,int iStart, int iMiddle, int iEnd, list *dst)
{
  int ii = iStart;
  int jj = iMiddle;
  int kk;

  for (kk = iStart; kk < iEnd; kk++) {
    if (ii < iMiddle && (jj >= iEnd || src->data[ii] <= src->data[jj])) {
      dst->data[kk] = src->data[ii];
      ii = ii+1;
    } else {
      dst->data[kk] = src->data[jj];
      jj = jj+1;
    }
  } 
}
