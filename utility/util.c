#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
    struct stat st;
    stat(argv[1], &st);

    printf("#File information: \n");
    if((st.st_mode & _S_IFDIR) == _S_IFDIR)
        printf("   file is directory\n");
    if((st.st_mode & _S_IFREG) == _S_IFREG)
        printf("   file is regular\n");


    if((st.st_mode & S_IREAD) == S_IREAD)
        printf("   can read it\n");
    if((st.st_mode & S_IWRITE) == S_IWRITE)
        printf("   can write it\n");
    if((st.st_mode & S_IEXEC) == S_IEXEC)
        printf("   can execute it\n");
    return 0;
}