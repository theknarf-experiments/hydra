#include "list.h"

#include <jansson.h>
#include <stdio.h>
#include <string.h>

void handle_requirement(char* name, json_t* obj)
{
	if(json_is_string(obj))
	{
		printf("%s: %s\n", key, json_string_value(obj));
	}


}

void process_json_file(json_t* root)
{
	if(!json_is_object(root))
	{
		fprintf(stderr, "Json root is not an object\n");
		return;
	}

	json_t* require = json_object_get(root, "require");

	if(!json_is_object(require))
		return;

	const char *key;
	json_t* value;
	json_object_foreach(require, key, value) {
		handle_requirement(key, value);
	}
}

void wpm_list()
{
	// Open file
	FILE* fp = fopen("dep.json", "rb");
	if( !fp ) fprintf(stderr, "Error opening dep.json"),exit(1);

	// Get filesize
	long lSize;
	fseek( fp , 0L , SEEK_END);
	lSize = ftell( fp );
	rewind( fp );

	// Allocate memory
	char *buffer;
	buffer = calloc( 1, lSize+1 );
	if( !buffer ) fclose(fp),fprintf(stderr, "memory alloc fails\n"),exit(1);

	// Read file
	if( 1!=fread( buffer , lSize, 1 , fp) )
		fclose(fp),free(buffer),fprintf(stderr,"entire read fails\n"),exit(1);

	// Close file
	fclose(fp);

	// Parsing the json
	json_error_t error;
	json_t* root = json_loads(buffer, 0, &error);
	free(buffer);

	if(!root)
		fprintf(stderr, "json read error on line %d: %s\n", error.line, error.text), exit(1);

	process_json_file(root);

	json_decref(root);
}
