#include "fileio.h"

int main()
{
    const char *filename = "data/fruits.list";
    struct strlist *items;

    items = read_strlist(filename);
    print_strlist(items);
    delete_strlist(items);

    return 0;
}
