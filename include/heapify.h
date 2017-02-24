#ifndef HEAPIFY_H
#define HEAPIFY_H

#include "utils.h"

void heapify(list *src);
void sift_down(list *src, size_t start, size_t end);

#endif
