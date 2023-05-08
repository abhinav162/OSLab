#include<unistd.h>
#include<stdio.h>

int main()
{
    int fd[2];
    pipe(fd);  // pipe() creates a unidirectional pipe and return two fd // fd[0] for read end and fd[1] for write end
    
    int pid = fork();
    if(pid == 0)
    {
        sleep(5);
        printf("Child Received data from pipe\n");
        char buff[100];
        read(fd[0], buff, sizeof(buff));  // read() is a blocking call // it will wait until data is available in pipe and read data fron read end of pipe fd[0]
        write(1, buff, sizeof(buff));
    }
    else
    {
        printf("Parent sending data to pipe\n");
        char buff[100] = "Hello Child";
        write(fd[1], buff, sizeof(buff)); // write data to write end of pipe fd[1]
    }

    return 0;
}