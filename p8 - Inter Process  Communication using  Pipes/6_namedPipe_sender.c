#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
    int re;
    re = open("namedpipe1", O_WRONLY);
    write(re,"Hello msg",sizeof("Hello msg"));
    printf("Data sent to named pipe from sender having PID : %d\n",getpid());    
}