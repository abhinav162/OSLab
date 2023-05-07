#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3, pid4, pid5, pid6, pid7;
    int status;

    pid1 = getpid();
    printf("P1 process with pid %d\n", pid1);

    pid2 = fork();
    if (pid2 == 0) {
        pid3 = fork();
        if (pid3 == 0) {
            pid4 = fork();
            if (pid4 == 0) {
                printf("P4 process with pid %d (orphan)\n", getpid());
                sleep(10);
            } else {
                printf("P3 process with pid %d and child P4 with pid %d\n", getpid(), pid4);
                waitpid(pid4, &status, 0);
            }
        } else {
            printf("P2 process with pid %d and child P3 with pid %d\n", getpid(), pid3);
            waitpid(pid3, &status, 0);
        }
    } else {
        pid5 = fork();
        if (pid5 == 0) {
            pid6 = fork();
            if (pid6 == 0) {
                pid7 = fork();
                if (pid7 == 0) {
                    printf("P7 process with pid %d (zombie)\n", getpid());
                } else {
                    printf("P6 process with pid %d and child P7 with pid %d\n", getpid(), pid7);
                }
            } else {
                printf("P5 process with pid %d and child P6 with pid %d\n", getpid(), pid6);
                waitpid(pid6, &status, 0);
            }
        } else {
            printf("P1 process with pid %d and children P2 with pid %d, P5 with pid %d\n", pid1, pid2, pid5);
            waitpid(pid2, &status, 0);
            waitpid(pid5, &status, 0);
        }
    }

    return 0;
}