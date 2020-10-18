#include <stdio.h>
#include <unilibfile.h>

#ifdef _WIN32
int uniopen(const char *pathname, int flags, mode_t mode)
{
    return _open(pathname, flags, mode);
};
#elif __linux__
int uniopen(const char *pathname, int flags, mode_t mode)
{
    return open(pathname, flags, mode);
};
#endif

int uniclose(int fd)
{
    return close(fd);
};

ssize_t uniwrite(int fd, const void *buf, size_t size)
{
    return write(fd, buf, size);
};

ssize_t uniread(int fd, void *buf, size_t size)
{
    return read(fd, buf, size);
};

int uniremove(const char *pathname)
{
    return remove(pathname);
}

int unirename(const char *old, const char *new)
{
    return rename(old, new);
}

int uniseek(int fd, off_t offset, int whence)
{
    return seek(fd, offset, whence);
}