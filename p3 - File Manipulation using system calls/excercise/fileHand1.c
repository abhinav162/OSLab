#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    char buffer[20];
    // char *buffer = (char *) calloc(100, sizeof(char));
    int file = open("file1.txt",O_WRONLY|O_CREAT|O_APPEND,0777);
    int input = read(0,&buffer,20);
    write(file,&buffer,20);
    
    
    char buffer2[20];
    int x = open("file1.txt",O_RDONLY,0777);
    read(x,&buffer2,20);
    write(1,&buffer2,20);
}