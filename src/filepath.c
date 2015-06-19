//
// Created by Frank Lyder Bredland on 14/06/15.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "filepath.h"
#include "variables.h"

char* fullpath(const filepath* fp) {
    char* file_path;
    concat(file_path, fp->path, "/", fp->name);
    return file_path;
}

filepath *new_filepath(const char *const name, const char *const path) {
    filepath* fp = calloc(1, sizeof(filepath));

    fp->name = calloc(strlen(name) + 1, sizeof(char));
    strcpy(fp->name, name);

    fp->path = calloc(strlen(path) + 1, sizeof(char));
    strcpy(fp->path, path);

    return fp;
}

void free_filepath(filepath *fp) {
    free(fp->name);
    free(fp->path);
    free(fp);
}
