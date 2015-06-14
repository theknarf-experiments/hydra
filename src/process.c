#include "process.h"
#include "variables.h"
#include "filepath.h"

#include <stdlib.h>
#include <stdio.h>

void process_zip(const filepath* filepath) {
    char* result;

    concat(result, "cd ", filepath->path, " && unzip -u ", filepath->name);

    printf("Command: %s\n", result);
    system(result);
    free(result);
}

void process(const filepath* filepath) {
    // TODO: check if it is a zip file before trying to unzip it
    process_zip(filepath);
}
