#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    char buffer[100];
    int file = open("q3.txt",O_RDONLY);
    
    int size = lseek(file,0,SEEK_END);
    lseek(file,0,SEEK_SET);
    read(file,&buffer,size);
    write(1,&buffer,size);
}