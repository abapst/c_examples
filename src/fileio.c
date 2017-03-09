#include "fileio.h"
#include "list.h"


iolist *read_string_list(const char *filename)
{
    size_t n;
    FILE *fd = fopen(filename,"r");

    if(fd == NULL) {
        fprintf(stderr,"File %s not found!\n",filename);
        exit(-1);
    }

    int cnt = 0;
    char *buf = malloc(MAXLINE);
    node_t *list = list_init;

    while(NULL != fgets(buf,MAXLINE,fd)) {
         
    }

}
