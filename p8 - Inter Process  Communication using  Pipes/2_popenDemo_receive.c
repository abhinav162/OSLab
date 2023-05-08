#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    FILE *rd;
    char buffer[50];
    rd = popen("ls","r");
    fread(buffer,sizeof(char),sizeof(buffer),rd);
    write(1,buffer,sizeof(buffer));
    // printf("%s",buffer);
    pclose(rd);
}