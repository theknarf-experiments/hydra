#include "variables.h"

void concat_impl(void *result, char *sourceA, int num, ...) {
    va_list ap;

    size_t size = strlen(sourceA) + 1;

    va_start(ap, num);
    while(num--)
        size += strlen(va_arg(ap, char*));
    va_end(ap);

    result = calloc(size, sizeof(char));
    strcpy(result, sourceA);

    va_start(ap, num);
    while(num--)
        strcat(result, va_arg(ap, char*));
    va_end(ap);
}
