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
    list *v = create_list(n);
    
    float *step = v->data;

    /* Read list into array */
    while(fscanf(fd,"%f",step) > 0){
        step++;
    }

    fclose(fd);
    return v;
}

void swap(float *data, int i1, int i2)
{
    float tmp = data[i1];
    data[i1] = data[i2];
    data[i2] = tmp;
}

list *copy_list(list *src)
{
    size_t ii;
    list *dst = create_list(src->n);

    for(ii = 0; ii < src->n; ii++) {
        dst->data[ii] = src->data[ii];
    }

    return dst;
}

list *create_list(size_t n)
{
    list *v = (list *)malloc(sizeof(list));
    v->data = (float *)malloc(n*sizeof(float));
    v->n = n;

    return v;
}

void delete_list(list *v)
{
    free(v->data);
    free(v);
}

void print_list(list *v)
{
    size_t ii;

    for (ii = 0; ii < v->n; ii++)
        printf("%f\n",v->data[ii]);
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
