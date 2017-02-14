#include "utils.h"


list *read_list(const char *filename)
{
    size_t n;
    FILE *fd = fopen(filename,"r");

    if(fd == NULL){
        fprintf(stderr,"File %s not found!\n",filename);
        exit(-1);
    }

    /* Read length of list */
    fscanf(fd,"%zu",&n);

    /* Allocate list */
    list *src = create_list(n);
    
    float *step = src->data;

    /* Read list into array */
    while(fscanf(fd,"%f",step) > 0){
        step++;
    }

    fclose(fd);
    return src;
}

void swap(list *src, int i1, int i2)
{
    float tmp = src->data[i1];
    src->data[i1] = src->data[i2];
    src->data[i2] = tmp;
}

int copy_list(list *src, list *dst)
{
    size_t ii;
    if (src->n != dst->n) return -1;

    for(ii = 0; ii < src->n; ii++) {
        dst->data[ii] = src->data[ii];
    }

    return 0;
}

list *create_list(size_t n)
{
    list *src = (list *)malloc(sizeof(list));
    src->data = (float *)malloc(n*sizeof(float));
    src->n = n;

    return src;
}

void delete_list(list *src)
{
    free(src->data);
    free(src);
}

void print_list(list *src)
{
    size_t ii;

    for (ii = 0; ii < src->n; ii++)
        printf("%f\n",src->data[ii]);
}

int compare_lists(list *src, list *dst)
{
    size_t ii;
    if (src->n != dst->n) return -1;

    for (ii = 0; ii < src->n; ii++) {
        if (src->data[ii] != dst->data[ii]) return -1;
    }   
    return 0;
}

/**************************************************
 * Implicit heap functions
 **************************************************/

void heapify(list *src)
{
    size_t ii;

    if (src->n == 1)
        return;

    for(ii = src->n/2; ii > 0; ii--) {
        max_heapify(src,ii);
    }
}

void max_heapify(list *src, size_t ii)
{
    size_t left = 2*ii+1;
    size_t right = 2*ii+2;
    size_t largest = ii;

    /* percolate downwards until ii is largest in its subheap */
    if (left <= src->n && src->data[left] > src->data[largest])
        largest = left;
    if (right <= src->n && src->data[right] > src->data[largest])
        largest = right;
    if (largest != ii) {
        swap(src,ii,largest);
        max_heapify(src, largest);
    }
}

void sift_down(list *src, size_t start, size_t end)
{
    /* TODO */
}

/**************************************************
 * Returns the time in ms since the epoch
 **************************************************/
double get_time_ms()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);

    return (double)(tv.tv_sec) + (double)(tv.tv_usec/1E6);
}
