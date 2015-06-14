//
// Created by Frank Lyder Bredland on 13/06/15.
//

#ifndef WPM_SETTINGS_H
#define WPM_SETTINGS_H

#include <stdarg.h>
#include <string.h>

#define WPM_DEPENDENCY_FILE "wpm.json"
#define WPM_DEPENDENCY_FILE_OPENING_ERROR "Error opening wpm.json"
#define WPM_DEPENDENCY_INSTALL_DIR "wpm_modules"

#define NUMARGS(...)  (sizeof((int[]){__VA_ARGS__})/sizeof(int))

int strlen_all(int num, ...);

void strcat_all(char* result, int num, ...);

#define concat(result, sourceA, ...) \
            do { \
                result = (char*) calloc(strlen(sourceA)+strlen_all(NUMARGS(__VA_ARGS__), __VA_ARGS__)+1, sizeof(char)); \
                strcpy(result, sourceA); \
                strcat_all(result, NUMARGS(__VA_ARGS__), __VA_ARGS__); \
            } while(0)

#endif //WPM_SETTINGS_H
