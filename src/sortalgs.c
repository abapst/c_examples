#include "sortalgs.h"


void bubble_sort(list *src)
{
    size_t n = src->n;
    size_t ii;
    int swapped;

    while (n > 1) {
        swapped = 0;
        for (ii=1; ii<n; ii++) {
            if (src->data[ii-1] > src->data[ii]) {
                swap(src, ii-1, ii);
                swapped = 1;
            }
        }
        if(swapped)
            n--;
        else
            break;
    }
}


void selection_sort(list *src)
{
    size_t ii,jj;
    size_t iMin;

    for (jj=0; jj<src->n; jj++) {
      iMin = jj;
      for (ii=jj+1; ii<src->n; ii++) {
        if (src->data[ii] < src->data[iMin])
          iMin = ii;
      }

      if (iMin != jj)
        swap(src, iMin, jj);
    }
}


void insertion_sort(list *src)
{
    size_t ii,jj;

    for (ii=1; ii<src->n; ii++) {
        jj = ii;
        while (jj > 0 && src->data[jj] < src->data[jj-1]) {
            swap(src, jj-1, jj);
            jj--;
        }
    }
}


void mergesort(list *src)
{
    list *dst = create_list(src->n);
    copy_list(src, dst);
    TopDownSplitMerge(src, 0, src->n, dst);
    copy_list(dst, src);
    delete_list(dst);
}


void quicksort(list *src)
{
    qsort_main(src,0,src->n-1);
}


void qsort_main(list *src, int lo, int hi)
{
    int p; // pivot index
    if (lo < hi) {
        p = qsort_partition(src, lo, hi);
        qsort_main(src, lo, p-1);
        qsort_main(src, p+1, hi);
    }
}


int qsort_partition(list *src, int lo, int hi)
{
    float pivot = src->data[hi];
    int ii = lo; // place for swapping
    int jj;

    for (jj = lo; jj < hi; jj++) {
        if (src->data[jj] <= pivot) {
            swap(src, ii, jj);
            ii++;
        }
    }
    swap(src, ii, hi);
    return ii;
}


void TopDownSplitMerge(list *src, int iStart, int iEnd, list *dst)
{
  int iMiddle;
  if (iEnd - iStart < 2) return;

  iMiddle = (iEnd + iStart) / 2;
  /*
   * Alternating the merge direction with each level of recursion is
   * a trick to avoid the copy-back step
   */
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


void heapsort(list *src)
{
    size_t end = src->n-1;

    heapify(src);

    while (end > 0) {
        swap(src,0,end);
        end--;
        sift_down(src,0,end);
    }
}


void heapify(list *src)
{
    size_t end = src->n-1;
    size_t start = PARENT(end);

    if (src->n == 1)
        return;

    while (start != SIZE_MAX) {
        sift_down(src,start,end);
        start--;
    }
}


void sift_down(list *src, size_t start, size_t end)
{
    size_t child, iswap, root = start;

    while (LCHILD(root) <= end) {
        child = LCHILD(root);
        iswap = root;

        /* if left child is greater */
        if (src->data[iswap] < src->data[child])
            iswap = child;
        /* if right child is greater */
        if (child+1 <= end && src->data[iswap] < src->data[child+1])
            iswap = child+1;
        /* if root is largest, the heap property is satisfied */
        if (iswap == root) {
            return;
        } else {
            swap(src, root, iswap);
            root = iswap;
        }
    }
}
