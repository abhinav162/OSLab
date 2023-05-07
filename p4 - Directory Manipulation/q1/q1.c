#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
    //create a directory using directory system call and create a file inside it
    int check;
    char *dirname = "Practical4a";
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
    // create a character array command and use it to store the command to create a file inside the directory
    char command[50];
    sprintf(command,"touch %s/file1.txt",dirname);
    system(command);
    // system("touch Practical4a/file1.txt");
    system("ls Practical4a");
    return 0;
}