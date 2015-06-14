#include "list.h"
#include "variables.h"

#include <jansson.h>


void handle_requirement(const char* key, const json_t* obj)
{
	if(json_is_string(obj))
	{
		printf("%s: %s\n", key, json_string_value(obj));
	}
}

void process_json_file(const json_t* root, void(*handle)(const char*, const json_t*))
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
		handle(key, value);
	}
}

json_t* load_wpm_json()
{
	// Open file
	FILE* fp = fopen(WPM_DEPENDENCY_FILE, "rb");
	if( !fp ) fprintf(stderr, WPM_DEPENDENCY_FILE_OPENING_ERROR),exit(1);

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

	if(!root) {
		fprintf(stderr, "json read error on line %d: %s\n", error.line, error.text), exit(1);
	}

	return root;
}

void wpm_list()
{
	json_t* root = load_wpm_json();
	process_json_file(root, handle_requirement);
	json_decref(root);
}
