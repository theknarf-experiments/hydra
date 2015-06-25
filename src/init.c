//
// Created by Frank Lyder Bredland on 25/06/15.
//

#include <stdlib.h>
#include <stdio.h>

// Using PATH_MAX is a bad implementation, source: http://insanecoding.blogspot.no/2007/11/pathmax-simply-isnt.html
// TODO: rewrite functiontions using PATH_MAX so we don't have to rely on it
#ifdef  __APPLE__
#include <sys/syslimits.h>
#else
#define	PATH_MAX		 1024	/* max bytes in pathname */
#endif

char* normalize_path(const char *path) {
    // TODO:    implement this for windows
    //          look into [GetFullPathName](http://msdn.microsoft.com/en-us/library/aa364963%28v=VS.85%29.aspx) for windows

    // Implementation for *nix
    // Based on: [realpath](http://pubs.opengroup.org/onlinepubs/009695399/functions/realpath.html)
    char actualpath [PATH_MAX+1];
    return realpath(path, actualpath);
}

void wpm_init(const char *folder) {
    const char* folder_n = normalize_path(folder);

    printf("Original path: %s\nNormalize path: %s\n", folder, folder_n);
}
