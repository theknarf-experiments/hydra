#include "install.h"

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <curl/curl.h>

#define WPM_DEPENDENCY_INSTALL_DIR "dep"

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
	size_t written = fwrite(ptr, size, nmemb, stream);
	return written;
}

void wpm_install(char* name, char* path)
{
	printf("Downloading: %s\n", path);

	mkdir(WPM_DEPENDENCY_INSTALL_DIR, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	
	CURL *curl = curl_easy_init();

	if(curl)
	{
		char file_path[100];
		snprintf(file_path, sizeof file_path, "%s/%s",WPM_DEPENDENCY_INSTALL_DIR, name);

		printf("Writing to: %s\n", file_path);
		FILE *fp = fopen(file_path, "wb");

		curl_easy_setopt(curl, CURLOPT_URL, path);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		CURLcode res = curl_easy_perform(curl);

		fclose(fp);
	}
	else
	{
		fprintf(stderr, "curl error\n");
	}

	curl_easy_cleanup(curl);
}
