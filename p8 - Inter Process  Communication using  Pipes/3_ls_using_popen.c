#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    FILE *read_fp;
    char buffer[50];
    read_fp = popen("ls","r");
    fread(buffer,sizeof(char),sizeof(buffer),read_fp);  // fread() reads data from the given stream into the array pointed to, by ptr (ie, it will execute the command ls and store the output in buffer)
    write(1,buffer,sizeof(buffer));
}