#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	char buff[50];
	int fdi = open("input.txt",O_RDONLY,0777);
	read(fdi,&buff,sizeof(buff));

	int count = 0;
	for(int i = 0; i < sizeof(buff); i++)
	{
		if(buff[i] == '\n')
			count++;
	}

	printf("%d",count);
}
