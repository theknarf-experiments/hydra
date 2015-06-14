#include "variables.h"

int strlen_all(int num, ...) {
    int total = 0;
    va_list ap;

    va_start(ap, num);
    while(num--)
        total += strlen(va_arg(ap, char*));
    va_end(ap);

    return total;
}

void strcat_all(char* result, int num, ...) {
    va_list ap;

    va_start(ap, num);
    while(num--)
        strcat(result, va_arg(ap, char*));
    va_end(ap);

}