#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd = open("numbers.txt", O_RDWR|O_APPEND|O_CREAT, 0777);

    for(int i = 0; i < 100; i++)
    {
		char buff[4];
        int len = sprintf(buff, "%d\n", i);
        write(fd, buff, len);
    }

	lseek(fd,0,SEEK_SET);

	char obuff[50];
	read(fd, obuff, 50);

	int count = 0;
	for(int i = 0; i < 50;i++)
    {
        char ch = obuff[i];
        if(ch>='0'&&ch<='9' && count < 10)
        {
		printf("%c\n",obuff[i]);
		count++;
        }
    }
    
    close(fd);
    return 0;
}
