#include <stdlib.h>
#include <string.h>


void split_filename(char *filename, char **path, char **file, char **ext)
{
    *path = NULL;
    *file = NULL;
    *ext = NULL;

    char *next;
    char *current = filename;
    char *filestart;
    char *extstart;
    char slash = '/';
    char dot = '.';
    char nul = '\0';
    char *end = strchr(filename,(int)nul);

    /* Edge case 1 */
    if (!strcmp(filename,".")) {
        *path = malloc(2);
        strcpy(*path,".");
        return;
    }

    /* Edge case 2 */
    if (!strcmp(filename,"..")) {
        *path = malloc(3);
        strcpy(*path,"..");
        return;
    }

    /* Read path, if it exists */
    while(NULL != (next = strchr(current,(int)slash))) {
        next += 1;
        current = next;
    }
    if (current != filename) {
        *path =  malloc(current-filename+1);
        strncpy(*path, filename, current-filename);
        (*path)[current-filename] = 0; // null-terminate
    }
    filestart = current;

    if (*filestart == 0) {
        return; // no filename found after last slash
    }

    /* Read filename */
    next = strchr(current,(int)dot);
    if (next != NULL && next != filestart) {
        next += 1;
        current=next;

        current += (*next == 0) ? 1 : 0;

        *file = malloc(current-filestart);
        strncpy(*file, filestart, current-filestart-1);
        (*file)[current-filestart] = 0; // null-terminate
        extstart = current;

        if (*next == 0) {
            return;
        }

        *ext = malloc(end-extstart);
        strncpy(*ext, extstart, end-extstart);
    } else {
        *file = malloc(end-filestart);
        strncpy(*file, filestart, end-filestart);
        (*file)[end-filestart] = 0; // null-terminate
    }
}


char *build_filename(char *path, char *file, char *ext)
{
    size_t lpath = (path == NULL) ? 0 : strlen(path);
    size_t lfile = (file == NULL) ? 0 : strlen(file);
    size_t lext = (ext == NULL) ? 0 : strlen(ext);

    if ((lpath + lfile + lext) > 0) {
        char *filename = malloc(lpath + lfile + lext + 2);
        if (lpath > 0) {
            strcpy(filename,path);
        }
        if (lfile > 0) {
            strcpy(filename+lpath, file);
        }
        if (lext > 0) {
            filename[lpath + lfile] = '.';
            strcpy(filename+lpath+lfile+1,ext);
        }
        filename[lpath + lfile + lext + 2] = 0;
        return filename;
    } else
        return NULL;
}
