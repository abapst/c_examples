#include <stdlib.h>
#include <stdio.h>

#include "list.h"

int main()
{
    node_t *list = list_init();
    void *dummy = NULL;
    int ii;
  
    list->id = 0;
    print_list(list);

    for (ii = 1; ii < 10; ii++) {
        push_end(list,ii,dummy);
        print_list(list);
    }

    printf("<Reverse List>");
    list = reverse_list(list);
    printf(" Length = %d\n", list_length(list));
    print_list(list);

    for (ii = 1; ii < 10; ii++) {
        pop_end(&list);
        print_list(list);
    }
    delete_list(&list);
  
    return 0;
}
