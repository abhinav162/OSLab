#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

void isCreated(int check,int no)
{
    if(!check)
    {
        printf("Directory %d created successfully\n",no);
    }
    else
    {
        printf("Directory creation failed\n");
    }
}

int main()
{
    //create a directory using directory system call and create a file inside it
    int check;
    char *dirname = "Dir1";
    check=mkdir(dirname,0777);
    isCreated(check,1);
    char *dirname2 = "Dir2";
    check = mkdir(dirname2,0777);
    isCreated(check,2);

    printf("Items of main Directory\n");
    system("ls");

    system("touch Dir1/file1.txt");
    printf("List of Items inside Dir1\n");
    system("ls Dir1");

    //copy the content of one directory to another directory
    system("cp Dir1/file1.txt Dir2/copiedfile1.txt");
    printf("Copied Successfully\n");
    printf("List of Items inside Dir2\n");
    system("ls Dir2");
    return 0;
}