#include <stdlib.h>
#include <stdio.h>

#include "parse.h"


int main(int argc, char **argv)
{
    (void)argc;
    char *filename = argv[1];
    char *path;
    char *file;
    char *ext;

    split_filename(filename,&path,&file,&ext);
    char *fused = build_filename(path,file,ext);

    printf("Filename = %s\n",filename);
    printf("Path = %s\n",path);
    printf("File = %s\n",file);
    printf("Ext = %s\n",ext);
    printf("Fused = %s\n",fused);

    free(path);
    free(file);
    free(ext);
    free(fused);

    return 0;
}
