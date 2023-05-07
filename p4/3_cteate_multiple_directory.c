#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
    char name[] = "dir0";
    int i = 1;
    while(i <= 10)
    { 
        mkdir(name,0777);
        name[3] ='0' + i;
        i++;
    }
}