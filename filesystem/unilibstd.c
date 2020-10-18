#include <unilibc.h>

#ifdef _WIN32
    void *purealloc(size_t size)
    {
        return VirtualAlloc(NULL, size, MEM_COMMIT, PAGE_READWRITE); 
    };
#elif __linux__
    void *purealloc(size_t size)
    {
        return sbrk(size);
    };
#endif