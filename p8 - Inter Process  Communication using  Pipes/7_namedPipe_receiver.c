#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
    int re;
    re = open("namedpipe1",O_RDONLY);
    char buff[50];
    read(re,buff,sizeof(buff));
    printf("Data received from named pipe in receiver having PID : %d\n",getpid());
}