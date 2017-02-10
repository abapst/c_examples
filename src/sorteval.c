#include "utils.h"
#include "sortalgs.h"


int main(int argc, char **argv)
{
    const char *filename = argv[1];
    const char *truthname = argv[2];

    list *src = read_list(filename);
    list *truth = read_list(truthname);
    list *sorted = merge_sort(src); 

    printf("unsorted list:\n");
    print_list(src);
    printf("sorted list:\n");
    print_list(sorted);

    if (!compare_lists(truth, sorted))
        printf("sorted correctly!\n");
    else
        printf("sort is incorrect :(\n");
    
    delete_list(src);
    delete_list(sorted);
    delete_list(truth);
    return 0;
}
