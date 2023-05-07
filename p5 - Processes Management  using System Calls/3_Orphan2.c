// create program for orphan process

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    pid_t pid;
    pid = fork();
    if(pid==0)
    {
        sleep(6);
        printf("I am child having pid %d\n",getpid());
        printf("\nMy parent pid is : %d",getppid());
    }
    else
    {
        sleep(3);
        printf("I am parent PID is %d\n",getpid());
        printf("My child PID is %d\n",pid);
        printf("parent process completed\n");
    }
    return 0;
}