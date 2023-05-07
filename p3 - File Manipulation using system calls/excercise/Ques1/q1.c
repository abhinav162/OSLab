#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    write(1,"Write Something and end with $ : ",33);
    char buffer[100];
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

    int file = open("q1.txt",O_WRONLY|O_CREAT,0777);
    write(file,&buffer,count);

    int full_size = lseek(file,0,SEEK_END);
    lseek(file,0,SEEK_SET);

    // store first half of buffer in buffer2
    char buffer2[full_size/2];
    int f2 = open("q1.txt",O_RDONLY);
    read(f2,&buffer2,full_size/2);
    write(1,&buffer2,full_size/2);

    printf("\n");

    // store other half of buffer in buffer3 using lseek
    char buffer3[full_size/2];
    lseek(f2,full_size/2,SEEK_SET);
    read(f2,&buffer3,full_size/2);
    write(1,&buffer3,full_size/2);
}