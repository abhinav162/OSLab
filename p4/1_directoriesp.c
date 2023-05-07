#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
    int check;
    char *dirname = "Practical4";
    check=mkdir(dirname,0777);
    if(!check)
    {
        printf("Directory created successfully");
    }
    else
    {
        printf("Directory creation failed");
    }
    system("ls");
}