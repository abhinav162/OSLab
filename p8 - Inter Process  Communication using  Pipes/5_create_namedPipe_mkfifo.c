#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
    int res;
    res = mkfifo("namedpipe1",0777); // mkfifo() creates a named pipe and return 0 on success and -1 on failure, here a named pipe named namedpipe1 is created with read and write permission for all
    if(res == 0)
    {
        printf("Named pipe created\n");
    }
    else
    {
        printf("Named pipe creation failed\n");
    }
}