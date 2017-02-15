#ifndef __HEAPIFY_H__
#define __HEAPIFY_H__

#include "utils.h"

void heapify(list *src);
void sift_down(list *src, size_t start, size_t end);

#endif
