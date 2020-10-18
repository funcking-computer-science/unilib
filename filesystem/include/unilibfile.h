#ifndef UNILIB_FILE_H
    #define UNILIB_FILE_H
#include <unilibc.h>

#ifdef _WIN32
    #define UNILIB_APPEND           _O_APPEND
    #define UNILIB_BINARY           _O_BINARY
    #define UNILIB_CREAT            _O_CREAT

    //pmode
    #define UNILIB_READONLY         _S_IREAD
    #define UNILIB_WRONLY           _S_IWRITE
    #define UNILIB_RDWR             _S_IREAD | _S_IWRITE
#elif __linux__
    #define UNILIB_APPEND           O_APPEND
    // #define UNILIB_BINARY           O_BINARY
    #define UNILIB_CREAT            O_CREAT

    //pmode
    #define UNILIB_READONLY         S_IRUSR
    #define UNILIB_WRONLY           S_IWUSR
    #define UNILIB_RDWR             S_IRWXU 
#endif

int uniopen(const char *pathname, int flags, mode_t mode);
int uniclose(int fd);
ssize_t uniwrite(int fd, const void *buf, size_t size);
ssize_t uniread(int fd, void *buf, size_t size);
int uniremove(const char *pathname);
int unirename(const char *old, const char *new);
int uniseek(int fd, off_t offset, int whence);

#endif