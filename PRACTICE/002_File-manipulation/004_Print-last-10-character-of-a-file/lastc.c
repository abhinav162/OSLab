#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{

	int fd = open("input.txt",O_RDONLY,0777);
	char buff[500];
	read(fd,buff,sizeof(buff));
	int pos = lseek(fd,0,SEEK_END);
	for(int i = pos-10; i <= pos; i++)
	{
		printf("%c",buff[i]);
	}
}
