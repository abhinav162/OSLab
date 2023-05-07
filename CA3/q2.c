// write a program using system calls for operation on processes to create a hierarchy of processes P1->P2->P3->P4 and verify the relationship using getpid() and getppid()

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Current process P1
    printf("P1: Process ID = %d\n", getpid());

    // Create process P2
    int pid2 = fork();
    if (pid2 == 0) {
        // Child process P2
        printf("P2: Process ID = %d\n", getpid());
        
        // Create process P3
        int pid3 = fork();
        if (pid3 == 0) {
            // Child process P3
            printf("P3: Process ID = %d, Parent Process ID = %d\n", getpid(), getppid());
            
            // Create process P4
            int pid4 = fork();
            if (pid4 == 0) {
                // Child process P4
                printf("P4: Process ID = %d, Parent Process ID = %d\n", getpid(), getppid());
            }
            else {
                // Parent process P3
                wait(NULL);
                printf("P3: Child process P4 finished.\n");
            }
        }
        else {
            // Parent process P2
            wait(NULL);
            printf("P2: Child process P3 finished.\n");
        }
    }
    else {
        // Parent process P1
        wait(NULL);
        printf("P1: Child process P2 finished.\n");
    }
}