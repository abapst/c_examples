#include "heapify.h"

#define PARENT(i)    ( (i-1) / 2 )
#define LCHILD(i)    ( 2*i + 1 )
#define RCHILD(i)    ( 2*i + 2 )

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
