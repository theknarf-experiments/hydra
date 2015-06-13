#ifndef LIST_H
#define LIST_H

#include <jansson.h>

void wpm_list();
json_t* load_wpm_json();
void process_json_file(const json_t* root, void(*handle)(const char*, const json_t*));
void wpm_install_from_file();

#endif
