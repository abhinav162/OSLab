#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    char buffer[200];
    int file = open("file1.txt",O_RDONLY|O_CREAT,0777);

    read(file,&buffer,200);
    for(int i = 0; i < 200;i++)
    {
        char ch = buffer[i];
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
        {
            printf("%c",buffer[i]);
        }
    }
}