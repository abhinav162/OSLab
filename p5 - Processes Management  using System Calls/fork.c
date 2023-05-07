// P1 -> P2
// P1 -> P3
// ONE PARENT TWO CHILDREN

#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<fcntl.h>

int main()
{
	printf("Current process pid is : %d \n",getpid());
    pid_t c = fork();
	if(c == 0)
	{
		printf("\nchild pid is: %d, parent pid is: %d",getpid(),getppid());
	}
    else if(c > 0)
    {
        pid_t d = fork();
        if(d == 0)
        {
            printf("\nchild pid is: %d, parent pid is: %d",getpid(),getppid());
        }
        else if(d > 0)
        {
            wait(NULL);
            printf("\nchild pid is: %d, parent pid is: %d",getpid(),getppid());
        }
    }
	return 0;
}