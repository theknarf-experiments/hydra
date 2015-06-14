//
// Created by Frank Lyder Bredland on 14/06/15.
//

#ifndef WPM_FILEPATH_H
#define WPM_FILEPATH_H

typedef struct {
    char* name;
    char* path;
} filepath;

filepath* new_filepath(const char* const name, const char* const path);
void free_filepath(filepath*);
char* fullpath(const filepath* fp);

#endif //WPM_FILEPATH_H
