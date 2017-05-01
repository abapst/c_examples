#ifndef PARSE_H
#define PARSE_H

void split_filename(char *filename, char **path, char **file, char **ext);
char *build_filename(char *path, char *file, char *ext);

#endif
