#include "fileio.h"

int main()
{
    const char *filename = "data/fruits.list";
    struct strlist *items;

    items = read_string_list(filename);
    print_strlist(items);
    delete_strlist(items);

    return 0;
}
