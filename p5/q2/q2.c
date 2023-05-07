// write a program using system calls for operation on processes to create a hierarchy of processes P1->P2->P3 AND P1->P4->P5.Also simulate p4 as orphan and p5 as zombie process.
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

        // Create process P4
        int pid4 = fork();
        if (pid4 == 0) {
            // Child process P4
            printf("P4: Process ID = %d, Parent Process ID = %d\n", getpid(), getppid());

            // Simulate orphan process
            sleep(10);
            printf("P4: Parent process finished.\n");
        }
        else {
            // Parent process P1
            wait(NULL);
            printf("P1: Child process P4 finished.\n");

            // Create process P5
            int pid5 = fork();
            if (pid5 == 0) {
                // Child process P5
                printf("P5: Process ID = %d, Parent Process ID = %d\n", getpid(), getppid());
                
                // Simulate zombie process
                exit(0);
            }
            else {
                // Parent process P1
                wait(NULL);
                printf("P1: Child process P5 finished.\n");
            }
        }
    }

    return 0;
}