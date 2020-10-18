#ifndef UNILIBC_H
    #define UNILIBC_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifdef WIN32
    #include <windows.h>
    #include <io.h>
#elif __linux__
    #include <unistd.h>
#endif

void *purealloc(size_t size);

#endif