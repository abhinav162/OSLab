// Zombie process is a process that has completed execution but still has an entry in the process table.
// It is a process in the terminated state but whose parent has not yet called wait() system call.
// So, it stays in the process table.
// A child process always first becomes a zombie before being removed from the process table.

// To check the zombie process, run the program and then run the command "ps -elf | grep defunct" in the terminal.



#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    pid_t a;
    a=fork();
    if(a > 0)
    {
        sleep(20);
        printf("PID of parent %d", getpid());
    }
    else
    {
        printf("PID of child %d", getpid());
        exit(0);
    }
    return 0;
}