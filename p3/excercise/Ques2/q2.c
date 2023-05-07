#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    char buffer[40];
    int i = 0,count = 0;
    while(i<40)
    {
        read(0,&buffer[i],1);
        if(buffer[i] != '$')
        {
            i++;
            count++;
        }
        else
        {
            break;
        }
    }

    int file = open("q2.txt",O_WRONLY|O_CREAT,0777);
    write(file,&buffer,count);
}