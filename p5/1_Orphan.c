// create program for orphan process

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    int pid;
    pid = getpid();
    printf("current process pid is %d\n",pid);
    printf("forking a child process\n");
    pid = fork();
    if(pid==0)
    {
        printf("child process is sleeping for 10 seconds\n");
        sleep(10);
        printf("\norphan child parent id : %d",getppid());
    }
    else
    {
        printf("parent process completed\n");
    }
    return 0;
}