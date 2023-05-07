#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fdi = open("input.txt",O_RDONLY,0777);
	char inbuff[50];
	int rsize = read(fdi,&inbuff,50);

	int fd2 = open("output.txt",O_WRONLY|O_CREAT,0777);
	write(fd2,&inbuff,rsize);
}
