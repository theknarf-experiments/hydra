//
// Created by Frank Lyder Bredland on 13/06/15.
//

#ifndef WPM_SETTINGS_H
#define WPM_SETTINGS_H

#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#define WPM_DEPENDENCY_FILE "wpm.json"
#define WPM_DEPENDENCY_FILE_OPENING_ERROR "Error opening wpm.json"
#define WPM_DEPENDENCY_INSTALL_DIR "wpm_modules"

void* concat_impl(char *sourceA, int num, ...);

#define NUMARGS(...) (sizeof((int[]){0, ##__VA_ARGS__})/sizeof(int)-1)
#define concat(result, sourceA, ...) \
            do { \
                result = concat_impl(sourceA, NUMARGS(__VA_ARGS__), __VA_ARGS__); \
            } while(0)

#endif //WPM_SETTINGS_H
