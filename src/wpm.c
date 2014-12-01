#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "install.h"

void help_option()
{
	printf("wpm (Whale package manger)\nusage: \n");
}

int process_command_line_args(int argc, char* argv[])
{
	if(argc < 2)
		return 1;

	if(strcmp(argv[1], "install")==0)
	{
		if(argc < 4)
			return 1;

		wpm_install(argv[2],argv[3]);
	}

	return 0;
}

int main(int argc, char* argv[])
{
	if(process_command_line_args(argc, argv))
	{
		help_option();
		return 1;
	}

	return 1; 
}
