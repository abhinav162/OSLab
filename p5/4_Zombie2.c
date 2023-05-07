#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    pid_t pid;
    pid = fork();
    if(pid==0)
    {
        printf("I am child having pid %d\n",getpid());
        printf("\nMy parent pid is : %d",getppid());
    }
    else
    {
        // wait(NULL); // wait for child to complete
        sleep(3);  // to remove zombie condition also we can use wait(NULL) system call
        printf("I am parent PID is %d\n",getpid());
        printf("My child PID is %d\n",pid);
        printf("parent process completed\n");
    }
    return 0;
}