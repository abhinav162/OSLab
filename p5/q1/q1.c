// write a program using system call for operations on processes to create a hierarchy of processes P1->P2->P3. ALSO print the id and parent id of each process.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int n;
    printf("\nEnter the number of child processes: ");
    scanf("%d", &n);
    
    pid_t pid = getpid();
    printf("\nCurrent process PID is %d ", pid);

    for (int i = 0; i < n; i++)
    {
        printf("\nForking a child process...");
        pid_t child_pid = fork();
        if (child_pid == -1)
        {
            printf("\nFailed to fork a child process.");
            return 1;
        }
        else if (child_pid == 0)
        {
            printf("\nChild process PID: %d, Parent process PID: %d ", getpid(), getppid());
            printf("\nForking a child process...");
            pid_t child_pid = fork();
            if (child_pid == -1)
            {
                printf("\nFailed to fork a child process.");
                return 1;
            }
            else if (child_pid == 0)
            {
                printf("\nChild process PID: %d, Parent process PID: %d ", getpid(), getppid());
            }
            else
            {
                printf("\nParent process PID: %d ", getpid());
            }
        }
        else
        {
            printf("\nParent process PID: %d  ", getpid());
        }
    }

    return 0;
}